class Solution {
public:
    
    int solve(int i, int j, string& w1, string& w2, int n1, int n2,  vector<vector<int>>& dp){
        
        //base case
        if(j >= n2){
            return dp[i][j] = n1-i;
        }

        if(i >= n1){
            return dp[i][j] = n2-j;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        //logic
        if(w1[i] == w2[j]){
            return dp[i][j] = solve(i+1, j+1, w1, w2, n1, n2, dp);
        }
        else{
            int insert  = solve(i, j+1, w1, w2, n1, n2, dp);
            int del     = solve(i+1, j, w1, w2, n1, n2, dp);
            int replace = solve(i+1, j+1, w1, w2, n1, n2, dp);

            return dp[i][j] = 1+min({insert, del, replace});
        }
    }

    int minDistance(string word1, string word2) {
        
        int n1 = word1.size();
        int n2 = word2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
        return solve(0 , 0 , word1, word2, n1, n2, dp);
    }
};