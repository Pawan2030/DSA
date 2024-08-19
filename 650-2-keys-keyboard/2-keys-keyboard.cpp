class Solution {
public:

    int minSteps(int n) {

        if(n == 0 || n == 1) return 0;
        if(n == 2) return 2;

        vector<int> arr(n+1);
        arr[0] = 0;
        arr[1] = 0;
        arr[2] = 2;

        for(int i=3; i<=n ; i++){
             
             int fact = i/2;

             while(fact >= 1){

                if(i%fact == 0){

                    arr[i] = arr[fact] + 1 + (i/fact - 1);
                    break;
                }
                else{
                    fact--;
                }
             }
        }
        return arr[n];
    }
};