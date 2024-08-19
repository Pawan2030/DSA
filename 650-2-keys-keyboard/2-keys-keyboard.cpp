class Solution {
public:
    
    int t[1001][1001];

    int solve(int n , int curr , int clip){

        if(curr == n){
            return 0;
        }

        if(curr > n){
            return 100000;
        }

        if(t[curr][clip] != -1){
            return t[curr][clip];
        }

        int Copy_Paste = 2 + solve(n , curr+curr, curr);
        int Paste      = 1 + solve(n , curr+clip, clip);

        return t[curr][clip] = min(Copy_Paste , Paste);
    }

    int minSteps(int n) {
        
        if(n == 1){
            return 0;
        }
        
        memset(t , -1 , sizeof(t));
        int curr  = 1;
        int clip = 1;

        return solve(n , curr , clip)+1;
    }
};