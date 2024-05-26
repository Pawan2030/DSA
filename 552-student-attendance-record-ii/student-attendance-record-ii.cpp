class Solution {
public:
    
    int MOD = 1000000007;
    int t[100001][2][3]; //n , ab , cl


    int solve(int n , int ab , int cl){
         
         //purning
        if(ab > 1 || cl > 2){
            return 0;
         }

        //base case
        if(n == 0){
            return 1;
        }

        if(t[n][ab][cl] != -1){
            return t[n][ab][cl];
        }

        int A = solve(n-1 , ab+1 , 0) %MOD;
        int L = solve(n-1 , ab ,  cl+1) %MOD;
        int P = solve(n-1 , ab , 0) %MOD;

        return t[n][ab][cl] = ((A+L)%MOD + (P%MOD))%MOD;
    }

    int checkRecord(int n) {

        int ab = 0;
        int cl = 0;

        memset(t , -1 , sizeof(t));

        return solve(n , ab , cl);
        
    }
};