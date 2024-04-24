class Solution {
public:

   int t[38];

   int solve(int n){

    if(n==0) return 0;
    if(n==1 || n==2) return 1;

    if(t[n] != -1) return t[n];

     int sum = 0;   
     sum += (solve(n-1) + solve(n-2) + solve(n-3) );

    return t[n] = sum;
   }

    int tribonacci(int n) {

       memset(t , -1 , sizeof(t));
       return solve(n);
        
        
    }
};