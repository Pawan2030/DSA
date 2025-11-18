class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n =  nums.size();
        unordered_map<int,int> mp;

        for(int i=0; i<n; i++){

            int num  = nums[i];
            int rest = target - num;

            if(mp.find(rest) != mp.end()){
                return {mp[rest] , i};
            }
            else{
                mp[num] = i;
            }
        }

        return {};
    }
};