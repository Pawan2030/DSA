class Solution {
public:

    int n;
    int dp[101];

    int solve(int i, string& s){
        
        if(dp[i] != -1){
            return dp[i];
        }

        if(i==n){
           return 1;
        }

        if(s[i] == '0'){
            return dp[i] = 0;
        }

        int way = 0;

        way += solve(i+1, s);

        if(i+1 < n && (s[i] == '1' || s[i] == '2' && s[i+1] <= '6')){
            way += solve(i+2 , s);
        }

        return dp[i] = way;
    }

    int numDecodings(string s) {
        n = s.size();
        memset(dp, -1, sizeof(dp));
        return solve(0 , s);
    }
};