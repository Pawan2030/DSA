class Solution {
public:

    int t[100001][2][3];

    #define MOD 1000000007

    int solve(int n , int absent , int cl){

        //base case

        if(absent >= 2 || cl >= 3){
            return 0;
        }

        if( n == 0){
            return 1;
        }

        if(t[n][absent][cl] != -1){
            return t[n][absent][cl];
        }

        int P = solve(n-1 , absent   , 0) % MOD ;
        int A = solve(n-1 , absent+1 , 0) % MOD ;
        int L = solve(n-1 , absent   , cl+1) % MOD ;

        return t[n][absent][cl] = ( (P + L) % MOD  +  A) % MOD ;

    }

    int checkRecord(int n) {
        
        memset(t , -1 , sizeof(t));
        // n  Absent , cl
        return solve(n , 0 , 0);
        
    }
}; 