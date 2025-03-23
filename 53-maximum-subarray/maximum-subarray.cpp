class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int n = nums.size();
        int currsum = nums[0];
        int totalsum = nums[0];

        for(int i=1; i<n; i++){
            currsum = max(nums[i] , currsum + nums[i]);
            totalsum = max(totalsum , currsum);
        }

        return totalsum;
    }
};