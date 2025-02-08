class Solution {
public:
     
    vector<vector<int>> res;
    int n;

    void solve(vector<int>& nums, vector<int>& temp, unordered_map<int,int>& mp){

        if(temp.size() == n){
            res.push_back(temp);
            return;
        }

        for(int i=0; i<n; i++){

            if(i > 0 && nums[i] == nums[i-1]) continue;

            if(mp[nums[i]] > 0){
                mp[nums[i]]--;
                temp.push_back(nums[i]);
                solve(nums,temp,mp);
                temp.pop_back();
                mp[nums[i]]++;
            }
        }

    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        n = nums.size();
        sort(begin(nums) , end(nums));
        vector<int> temp;
        unordered_map<int,int> mp;

        for(int num : nums){
            mp[num]++;
        }

        solve(nums,temp,mp);
        return res;
    }
};