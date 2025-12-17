class Solution {
public:
    
    int n1 , n2;
    int t[1001][1001];

    int solve(int i , int j , string &text1 , string &text2){

        if(i >= n1 || j >= n2) return 0;

        if(t[i][j] != -1) return t[i][j];

        if(text1[i] == text2[j]){
            return t[i][j] =  1 + solve(i+1, j+1 , text1 , text2);
        }

        return t[i][j] = max(solve(i+1,j,text1,text2) , solve(i,j+1,text1,text2));
    }

    int longestCommonSubsequence(string text1, string text2) {
        
        n1 = text1.size();
        n2 = text2.size();
        
        int dp[n1+1][n2+1];

        for(int i=0; i<=n1; i++){
            for(int j=0; j<=n2; j++){
                dp[i][j] = 0;
            }
        }

        for(int i=1; i<=n1; i++){
            for(int j=1; j<=n2; j++){

                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                }

            }
        }

        return dp[n1][n2];
    }
};