class Solution {
public:

    bool check(vector<vector<char>>& board , int sr , int er , int sc , int ec){

        unordered_set<int> st;

        for(int i=sr; i<=er; i++){
            for(int j=sc; j<=ec; j++){
                
                if(board[i][j] == '.') continue;

                if(st.count(board[i][j])){
                    cout<<"1"<<endl;
                    return false;
                }
                st.insert(board[i][j]);
            }
        }
        
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {

        int n = 9;
        
        //row check
        for(int i=0; i<n; i++){

            unordered_set<int> st;

            for(int j=0; j<n; j++){

                if(board[i][j] == '.') continue;
                
                if(st.count(board[i][j])){
                     cout<<"2"<<endl;
                     return false;
                }
                st.insert(board[i][j]);
            }
        }

        //col check

        for(int i=0; i<n; i++){
            unordered_set<int> st;

            for(int j=0; j<n; j++){

                if(board[j][i] == '.') continue;
                
                if(st.count(board[j][i])){
                    cout<<"3"<<endl;
                    return false;
                }
                st.insert(board[j][i]);
            }
        }

        // 3*3 grid check

        for(int i=0; i<n; i+=3){

             int sr = i;
             int er = i+2;

            for(int j=0; j<n; j+=3){

                int sc = j;
                int ec = j+2;

                if(!check(board , sr , er , sc , ec)){
                    return false;
                }   
            }
        }

        return true;
    }
};