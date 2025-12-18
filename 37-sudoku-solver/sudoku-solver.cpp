class Solution {
public:
    
    bool isPossible(int x , int y , char &ch , vector<vector<char>>& board){

        for(int i=0; i<9 ; i++){
            if(board[x][i] == ch){
                return false;
            }
        }

        for(int i=0; i<9 ; i++){
           if(board[i][y] == ch){
             return false;
           }
        }

        int sr = (x/3)*3;
        int er = sr+2;

        int sc = (y/3)*3;
        int ec = sc+2;

        for(int i = sr; i<= er; i++){
            for(int j=sc; j<=ec; j++){
                if(board[i][j] == ch){
                    return false;
                }
            }
        }

        return true;
    }

    bool helper(vector<vector<char>>& board){

         for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){

                if(board[i][j] == '.'){

                    for(char ch = '1' ; ch <= '9' ; ch++){

                        if(isPossible(i , j , ch , board)){

                            board[i][j] = ch;

                            if(helper(board)){
                                return true;
                            }
                            
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }

            }
        }

         return true;

    }
   

    void solveSudoku(vector<vector<char>>& board) {
        
        helper(board);
    
    }
};