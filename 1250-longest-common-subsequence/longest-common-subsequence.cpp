class Solution {
public:
    
    int n1;
    int n2;

    // int solve(int i, int j, string& t1, string& t2, vector<vector<int>>& dp){

    //     if(i >= n1 || j >= n2) return 0;

    //     if(dp[i][j] != -1){
    //          return dp[i][j];
    //     }

    //     if(t1[i] == t2[j]){
    //         return dp[i][j] = 1 + solve(i+1, j+1, t1 , t2, dp);
    //     }
    //     else{
    //         return dp[i][j] = max(solve(i, j+1, t1 , t2, dp) ,  solve(i+1, j, t1 , t2, dp));
    //     }
    // }

    int solveR(int i, int j, string& t1, string& t2, vector<vector<int>>& dp){

        if(i < 0 || j < 0) return 0;

        if(dp[i][j] != -1){
             return dp[i][j];
        }

        if(t1[i] == t2[j]){
            return dp[i][j] = 1 + solveR(i-1, j-1, t1 , t2, dp);
        }
        else{
            return dp[i][j] = max(solveR(i, j-1, t1 , t2, dp) ,  solveR(i-1, j, t1 , t2, dp));
        }
    }

    int solveTab(string& t1, string& t2){
       
        vector<vector<int>> dp(n1+1, vector<int>(n2+1 , 0));

        for(int i=1; i<= n1; i++){
            for(int j=1; j<= n2; j++){
                if(t1[i-1] == t2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i][j-1] ,  dp[i-1][j]);
                }
            }
        }
        return dp[n1][n2];
    }

    int longestCommonSubsequence(string text1, string text2) {
        
        n1 = text1.size();
        n2 = text2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1 , -1));
        return solveTab(text1,text2);
    }
};