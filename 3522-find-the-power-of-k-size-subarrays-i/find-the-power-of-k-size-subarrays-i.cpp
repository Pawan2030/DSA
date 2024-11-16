class Solution {
public:

    vector<int> resultsArray(vector<int>& nums, int k) {
        
        int n = nums.size();

        vector<int> res(n - k + 1 , -1); //[-1 , -1 , -1 , -1 ......]

        int i = 0;
        int j = 0;

        long long cons = 0;

        while(j < k){
            
            if(j == 0 || nums[j] == nums[j-1]+1){
                cons++;
            }

            j++;
        }

        if(cons == k){
            res[i] = nums[j-1];
        }

        while(j < n){

            i++;

            if(nums[i] == nums[i-1]+1)
              cons--;

            if(nums[j] == nums[j-1]+1){
                cons++;
            }

            if(cons == k){
                res[i] = nums[j];
            }
            j++;
        }

        return res;
    }
};