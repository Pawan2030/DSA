class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int currsum  = nums[0];
        int totalsum = nums[0];
        int n = nums.size();

        for(int i=1; i<n; i++){
           currsum  = max(nums[i]  , nums[i] + currsum);
           totalsum = max(totalsum , currsum); 
        }
        return totalsum;
    }
};