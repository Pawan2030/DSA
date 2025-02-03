class Solution {
public:
    
    int n;

    int checkIncreasing(vector<int>& nums){
       
       int cnt = 1;
       int ans = INT_MIN;

       for(int i=0; i<n-1; i++){
           
           if(nums[i] < nums[i+1]){
              cnt++;
           }
           else{
             cnt = 1;
           }

           ans = max(ans,cnt);
       } 
        return ans;
    }

    int checkDecreasing(vector<int>& nums){
       
       int cnt = 1;
       int ans = INT_MIN;

       for(int i=0; i<n-1; i++){
           
           if(nums[i] > nums[i+1]){
              cnt++;
           }
           else{
             cnt = 1;
           }

           ans = max(ans,cnt);
       } 
        return ans;
    }


    int longestMonotonicSubarray(vector<int>& nums) {
        
        n = nums.size();

        if(n == 1) return 1;
        int res = INT_MIN;
      
        res = max(res , checkIncreasing(nums));
        res = max(res , checkDecreasing(nums));

        return res;
    }
};