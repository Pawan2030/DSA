class Solution {
public:

    #define MOD 1000000007 
    //1e9 + 7 

    int solve(int n , vector<vector<vector<int>>> &t){

        //base case for i = 0th days

        for(int A = 0; A <= 1; A++){

            for(int L = 0; L <= 2; L++){
                 
                 t[0][A][L] = 1;
            }
         }
        
        for(int i = 1; i<=n; i++){

            for(int A = 0; A <= 1; A++){

                for(int L = 0; L <= 2; L++){

                     
                    long ans = t[i-1][A][0];
                    ans += ( A+1 <= 1 ? t[i-1][A+1][0] : 0);
                    ans += ( L+1 <= 2 ? t[i-1][A][L+1] : 0); 

                     t[i][A][L] = ans%MOD;  
                }
            }
        }

        return t[n][0][0];
    }

    int checkRecord(int n) {

        vector<vector<vector<int>>> t(n+1 , vector<vector<int>>(2 , vector<int>(3 ,0)));
        //int t[ n+1][absent][cosecutive_late]

        return solve(n , t);  
    }
};