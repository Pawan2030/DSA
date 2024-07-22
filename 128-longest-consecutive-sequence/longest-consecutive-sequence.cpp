class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if(nums.size() == 0){
            return 0;
        }
        
        sort(begin(nums) , end(nums));

        int mini = nums[0] - 1;
        int high = 0;
        int cnt = 0; 

        for(int i = 0; i<nums.size(); i++){

            if(nums[i]-1 == mini){
                mini = nums[i];
                cnt++;
                high = max(high , cnt);
            }
            else if(nums[i] == mini){
                continue;
            }
            else{
                cnt = 1;
                mini = nums[i];
            }
        }
        return high;
    }
};