class Solution {
public:
    

    bool isPlacePossible(int row, int col, vector<vector<string>>& temp, int n){

        for(int i=0; i<n; i++){
            if(i != row && temp[i][col] == "Q"){
                return false;
            }
        }

        // cross - top - left
        int i = row-1;
        int j = col-1;

        while(i >= 0 && j >=0){
            if(temp[i][j] == "Q") return false;
            i--;
            j--;
        }

        //top-right
        i = row-1;
        j = col+1;

        while(i>=0 && j<n){
           if(temp[i][j] == "Q") return false;
           i--;
           j++;
        }

        return true;
    }

    void add(vector<vector<string>>& board, vector<vector<string>>& temp, int n){
        
        vector<string> vec;

        for(int i=0; i<n; i++){

            string st = "";

            for(int j=0; j<n; j++){

                st += temp[i][j];
            }

            vec.push_back(st);
        }

        board.push_back(vec);
    }

    void solve(int sRow, vector<vector<string>>& board, vector<vector<string>>& temp, int n){

        if(sRow >= n){
            add(board, temp, n);
            return;
        }

        for(int col=0; col<n; col++){

            if(isPlacePossible(sRow, col, temp, n)){
                temp[sRow][col] = "Q";
                solve(sRow+1, board, temp, n);
                temp[sRow][col] = ".";
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>> board;
        vector<vector<string>> temp(n, vector<string>(n , "."));

        solve(0, board, temp, n);
        return board;
    }
};