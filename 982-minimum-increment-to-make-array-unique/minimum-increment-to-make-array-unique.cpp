class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        
        int n = nums.size();
        int minMove = 0;
        sort(begin(nums) , end(nums));

        for(int i=1; i<n; i++){

            if(nums[i-1] == nums[i]){
                nums[i] += 1;
                minMove += 1;
            }
            else if(nums[i-1] > nums[i]){
                minMove += ((nums[i-1] - nums[i]) + 1);
                nums[i] = nums[i-1] + 1;
            }
        }
        return minMove;
    }
};