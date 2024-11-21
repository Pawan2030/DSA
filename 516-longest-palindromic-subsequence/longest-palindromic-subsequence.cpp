class Solution {
public:
    
    int dp[1001][1001];

    int LCS(string &s1 , string &s2 , int n1 , int n2){

        if(n1 == 0 || n2 == 0){
            return 0;
        }

        if(dp[n1][n2] != -1){
            return dp[n1][n2];
        }

        if(s1[n1-1] == s2[n2-1]){
            int ans = 1+LCS(s1 , s2 , n1-1 , n2-1);
            return dp[n1][n2] = ans;
        }
        else{
            int l = LCS(s1 , s2 , n1-1 , n2);
            int r = LCS(s1 , s2 , n1 , n2-1);

            return dp[n1][n2] = max(l , r);
        }

    }

    int longestPalindromeSubseq(string s) {

       string s1 = s;
       //reverse(begin(s) , end(s));
       string s2 = string(s.rbegin() , s.rend());
       memset(dp , -1 , sizeof(dp));

       return LCS(s1 , s2 , s1.length(), s2.length());  
    }
};