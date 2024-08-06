class Solution {
public:
    
    int t[100001][2][3];
    int mod = 1e9+7;

    int solve(int n , int ab , int late){

        if(ab == 2 || late == 3 || n < 0){
            return 0;
        }

        if(n == 0){
            return 1;
        }

        if(t[n][ab][late] != -1) return t[n][ab][late];

        int ans = 0;
        ans =  (ans%mod + solve(n-1 , ab , 0)%mod); // for present
        ans =  (ans%mod + solve(n-1 , ab+1 , 0)%mod); // for absent
        ans =  (ans%mod + solve(n-1 , ab , late+1)%mod); // for late

        return t[n][ab][late] = ans%mod;
    }

    int checkRecord(int n) {
        
        memset(t , -1 , sizeof(t));
        return solve(n , 0 , 0);
    }
};