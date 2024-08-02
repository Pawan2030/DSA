class Solution {
public:
    int minSwaps(vector<int>& nums) {

       int n = nums.size();
       vector<int> prefix(2*n , 0);

       for(int i=0; i<(2*n); i++){
           
           prefix[i] = nums[i%n];
       }
    
       for(int i=1; i<(2*n); i++){
          prefix[i] += prefix[i-1];
       } 

       int windSize = prefix[n-1];

       if(windSize == 0) return 0;

       int ones = prefix[windSize-1];

       int miniSwap = windSize - ones;

       for(int i = windSize; i<(2*n); i++){
           
           ones = prefix[i];
           ones -= prefix[i-windSize];

           miniSwap = min(miniSwap , windSize-ones);
       }
        return miniSwap;
    }
};