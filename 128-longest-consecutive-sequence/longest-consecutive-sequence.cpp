class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if(nums.size() == 0){
            return 0;
        }
        
        sort(begin(nums) , end(nums));

        int mini = INT_MIN;
        int high = 0;
        int cnt = 1; 

        for(int i = 0; i<nums.size(); i++){

            if(nums[i]-1 == mini){
                mini = nums[i];
                cnt++;
            }
            else if(nums[i] != mini){
                cnt = 1;
                mini = nums[i];;
            }
            
            high = max(high , cnt);
        }
        return high;
    }
};