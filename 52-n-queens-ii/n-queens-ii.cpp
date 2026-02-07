class Solution {
public:

    bool isPossibleToPlace(int row, int col, int n, vector<vector<string>>& temp){

        //check for row
        for(int i=0; i<n; i++){
             if(i != row && temp[i][col] == "Q"){
                return false;
             }
        }

        //bottom to left
        int i = row-1;
        int j = col-1;

        while(i >= 0 && j >= 0){
             
             if(temp[i][j] == "Q"){
                return false;
             }
             i--;
             j--;
        }

        i = row-1;
        j = col+1;
        
        //bottom to left
        while(i>=0 && j<n){
            if(temp[i][j] == "Q"){
                return false;
            }
             i--;
             j++;
        }

        return true;
    }

    void solve(int row, int n, int &ans, vector<vector<string>>& temp){
        
        if(row == n){
            ans++;
            return;
        }

        for(int j=0; j<n; j++){

            if(isPossibleToPlace(row, j, n, temp)){
                    
                temp[row][j] = "Q";
                solve(row+1, n, ans, temp);
                temp[row][j] = ".";
            }
        }
        

    }

    int totalNQueens(int n) {

        vector<vector<string>> temp(n , vector<string>(n,"."));
        int ans = 0;
        solve(0, n, ans, temp);
        return ans; 
    }
};