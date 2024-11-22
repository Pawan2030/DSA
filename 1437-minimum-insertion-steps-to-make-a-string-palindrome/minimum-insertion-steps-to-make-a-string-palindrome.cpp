class Solution {
public:
    
    int dp[501][501];

    int LCS(string &s1 , string &s2 , int n1 , int n2){

        if(n1 == 0 || n2 == 0) return 0;

        if(dp[n1][n2] != -1) return dp[n1][n2];

        if(s1[n1-1] == s2[n2-1]){
            return dp[n1][n2] = 1+LCS(s1 , s2 , n1-1 , n2-1);
        }
        else{
            int l = LCS(s1 , s2 , n1-1  , n2);
            int r = LCS(s1 , s2 , n1    , n2-1);

            return dp[n1][n2] = max(l , r);
        }
    }
 
    int minInsertions(string s) {

        int n = s.length();   
        string s1 = s;
        reverse(begin(s) , end(s));
        memset(dp , -1 , sizeof(dp));

        int lcs = LCS(s1 , s , n , n);

        int minDeletion = n-lcs;
        int minInsertion = minDeletion;
        return minInsertion;
    }
};