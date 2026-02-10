class Solution {
public:
    
    int n1, n2;

    int solve(int i, int j, string& w1, string& w2, vector<vector<int>>& dp){

        //base case
        if(i >= n1){
            return n2-j;
        }

        if(j >= n2){
            return n1-i;
        }

        if(dp[i][j] != -1){
            return dp[i][j]; 
        }

        //logic
        if(w1[i] == w2[j]){
            return dp[i][j] = 0 + solve(i+1,j+1,w1,w2,dp);
        }
        else{

            int del1 = 1 + solve(i+1,j,w1,w2,dp);
            int del2 = 1 + solve(i,j+1,w1,w2,dp);

            return dp[i][j] = min(del1,del2);
        }
    }

    int minDistance(string word1, string word2) {
        
        n1 = word1.size();
        n2 = word2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
        return solve(0,0,word1,word2,dp);
    }
};