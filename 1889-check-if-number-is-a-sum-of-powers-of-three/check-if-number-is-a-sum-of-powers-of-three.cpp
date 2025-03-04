class Solution {
public:
    bool checkPowersOfThree(int n) {
         
        int p = 0;

        for(int i=0; i<n; i++){
             
            if(pow(3 , i) >= n) break;

            p++;
        }

        while(n > 0){

            if(n >= pow(3 , p)){
                n =  n - pow(3,p);
            }

            if(n >= pow(3 , p)) return false;

            p--;

        }
        
        return true;
    }
};