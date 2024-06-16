class Solution {
public:

    int minPatches(vector<int>& nums, int n) {
        
        int size = nums.size();
        int i = 0;
        int patch = 0;
        long sum = 0;

        while(sum < n){

            if(i < size && nums[i] <= sum + 1 ){
                sum += nums[i];
                i++;
            }
            else{
                sum += (sum+1);
                patch++;
            }
        }
        return patch;
    }
};