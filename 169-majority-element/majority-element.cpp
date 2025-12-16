class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int count = 0;
        int ans   = 0;

        for(int i=0 ; i<nums.size(); i++){

            if(count == 0) ans = nums[i];

            if(ans == nums[i]){
                count += 1;
            }
            else{
                count -= 1;
            }
        }
        return ans;
    }
};