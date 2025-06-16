class Solution {
public:

    int pivotIndex(vector<int>& nums) {
        
        int n = nums.size();
        int sum = accumulate(nums.begin() , nums.end() , 0);

        int add = 0;
        
        for(int i=0; i<n; i++){

            add = add + (i==0 ? 0 : nums[i-1]);
            sum -= nums[i];

            if(add == sum) return i;

        }

        return -1;
    }
};