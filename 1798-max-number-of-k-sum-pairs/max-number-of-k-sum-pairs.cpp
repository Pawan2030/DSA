class Solution {
public:

    int maxOperations(vector<int>& nums, int k) {
        
        int n = nums.size();
        int maxOp = 0;
        unordered_map<int,int> mp;

        for(int i=0; i<n; i++){

            int rest = k - nums[i];

            if(nums[i] > k){
                continue;
            }
            else if(mp[rest] > 0){
               maxOp++;
               mp[rest]--;
            }
            else{
                mp[nums[i]]++;
            }
        }
        return maxOp;
    }
};