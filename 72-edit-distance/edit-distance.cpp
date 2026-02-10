class Solution {
public:
    
    int n1;
    int n2;

    int solve(int i, int j, string& w1, string& w2){
        
        if(i < 0){
            return j+1;
        }
        
        if(j < 0){
            return i+1;
        }

        if(w1[i] == w2[j]){
            return solve(i-1, j-1, w1, w2);
        }
        else{

            int insert  = 1+ solve(i,j-1,w1,w2);
            int remove  = 1+ solve(i-1,j,w1,w2);
            int replace = 1+ solve(i-1,j-1,w1,w2);

            return min({insert,remove,replace});
        }
    }

    int solveTab(string& w1, string& w2){

        vector<vector<int>> dp(n1+1, vector<int>(n2+1,0));

        for(int i=0; i<=n1; i++){
            dp[i][0] = i;
        }

        for(int i=0; i<=n2; i++){
            dp[0][i] = i;
        }

        for(int i=1; i<=n1; i++){
            for(int j=1; j<=n2; j++){

                if(w1[i-1] == w2[j-1]){
                   dp[i][j] = dp[i-1][j-1];
                }
                else{
                    int insert  = 1 + dp[i][j-1];
                    int remove  = 1 + dp[i-1][j];
                    int replace = 1 + dp[i-1][j-1];

                    dp[i][j] = min({insert,remove,replace});
                }
            }
        }

        return dp[n1][n2];
    }

    int minDistance(string word1, string word2) {
        
        n1 = word1.size();
        n2 = word2.size();

        return solveTab(word1, word2);

    }
};