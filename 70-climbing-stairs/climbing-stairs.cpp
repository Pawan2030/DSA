class Solution {
public:
    
    int t[46];

    int solve(int n){
      if(n == 0 || n == 1){
          return 1;
      }
      if(t[n] != -1) return t[n];
      return solve(n-1) + solve(n-2);
    }

    int climbStairs(int n) {
        // memset(t , -1 , sizeof(t));
        // return solve(n);


        vector<int> res(n+1);

        res[0] = 1;
        res[1] = 1;

        for(int i=2; i<=n ; i++){
           res[i] = res[i-1] + res[i-2];
        }

        return res[n];

    }
};