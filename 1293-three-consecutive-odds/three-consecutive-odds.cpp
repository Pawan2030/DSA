class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {

        int n = arr.size();
        int i = 0;

        while(i < n){
             
            int cons = 0;
             
             while(i < n && arr[i]%2 != 0){
                  
                   cons++;
                   i++;

                   if(cons == 3){
                    return true;
                   }
             }
             i++;
        }
        return false;
    }
};