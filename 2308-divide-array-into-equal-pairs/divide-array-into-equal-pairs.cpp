class Solution {
public:
    bool divideArray(vector<int>& nums) {
        
        sort(begin(nums) , end(nums));
    
        for(int i=0; i<nums.size()-1; i+=2){
            int val = nums[i]^nums[i+1];

            if(val != 0) return false;
        }

        return true;
    }
};