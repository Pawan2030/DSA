class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        vector<int> ram;
        int s = nums.size();
        int i = 0;
        int j = 1;

        while (j < s) {
            if (nums[i] != nums[j]) {
                ram.push_back(nums[i]);
                i = j;
                j++;
            } 
            else{
                  while (j < s && nums[i] == nums[j])
                {
                        j++;
                }
                    i = j;
                    j++;
            
            }
        }
        
        if (i < s)
        {
            ram.push_back(nums[i]);
        }
        
        return ram;
    }
};
