class Solution {
public:
     
    vector<vector<int>> res;
    set<vector<int>> st;
    int n;

    void solve(vector<int>& nums, vector<int>& temp, unordered_map<int,int>& mp){

        if(temp.size() == n && st.find(temp) == st.end()){
            res.push_back(temp);
            st.insert(temp);
            return;
        }

        for(int i=0; i<n; i++){
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
        vector<int> temp;
        unordered_map<int,int> mp;

        for(int num : nums){
            mp[num]++;
        }

        solve(nums,temp,mp);
        return res;
    }
};