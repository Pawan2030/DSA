class Solution {
public:

    int n;
    //int dp[101];

    // int solve(int i, string& s){
        
    //     if(dp[i] != -1){
    //         return dp[i];
    //     }

    //     if(i==n){
    //        return 1;
    //     }

    //     if(s[i] == '0'){
    //         return dp[i] = 0;
    //     }

    //     int way = 0;

    //     way += solve(i+1, s);

    //     if(i+1 < n && (s[i] == '1' || s[i] == '2' && s[i+1] <= '6')){
    //         way += solve(i+2 , s);
    //     }

    //     return dp[i] = way;
    // }


    int tab(string &s){

        vector<int> dp(n+1 , 0);

        dp[n] =  1;

        for(int i=n-1; i>=0; i--){

            if(s[i] == '0'){
                dp[i] = 0;
                continue;
            }

            dp[i] += dp[i+1];

            if(i+1 < n && (s[i] == '1' || s[i] == '2' && s[i+1] <= '6')){
                dp[i] += dp[i+2];
            }
        }

        return dp[0];
    }


    int numDecodings(string s) {
        n = s.size();
        //memset(dp, -1, sizeof(dp));
        return tab(s);
    }
};