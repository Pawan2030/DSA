class Solution {
public:

    int maxAdjacentDistance(vector<int>& nums) {
        
        int n = nums.size();
        int maxDiff = INT_MIN;

        for(int i=0; i<2*n-1; i++){
             
             int idx1= i%n;
             int idx2= (i+1)%n;
             int diff = abs(nums[idx1] - nums[idx2]);
             maxDiff = max(maxDiff , diff);
        }
        return maxDiff;
    }
};