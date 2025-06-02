class Solution {
public:

    int candy(vector<int>& rating) {
        
        int n = rating.size();
        vector<int> leftTOright(n , 1);
        vector<int> rightTOleft(n , 1);

        for(int i=1; i<n; i++){

            if(rating[i-1] < rating[i]){
               leftTOright[i] = leftTOright[i-1]+1; 
            }
        }

        for(int i=n-2; i>=0; i--){

            if(rating[i+1] < rating[i]){
               rightTOleft[i] = rightTOleft[i+1]+1;  
            }
        }

        int res = 0;

        for(int i=0; i<n; i++){

            int val = max(leftTOright[i] , rightTOleft[i]);
            res += val;
        }

        return res;
    }
};