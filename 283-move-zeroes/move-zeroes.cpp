class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int n = nums.size();
        int i = 0;
        int j = i+1;

        while(j < n){

            while(i < n && nums[i] != 0){
                i++;
            }
            
            j = i+1;
            
            while(j < n && nums[j] == 0){
                j++;
            }
            
            if(i < n && j < n){
               swap(nums[i] , nums[j]);
            }

            i++;
            j = i+1;
        }
    }
};