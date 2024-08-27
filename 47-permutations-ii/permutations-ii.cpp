class Solution {
public:
    vector<vector<int>> res;
    int n;

    void solve(vector<int>& temp,  unordered_map<int,int>& mp) {

        // base case
        if (temp.size() == n) {
            res.push_back(temp);
            return;
        }

        // logic
        for (auto [num , freq] : mp) {
            
            if(freq > 0){
                temp.push_back(num);
                mp[num]--;
                solve(temp , mp);
                temp.pop_back();
                mp[num]++;
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {

        n = nums.size();
        vector<int> temp;
        unordered_map<int,int> mp;

        for(int &num : nums){
            mp[num]++;
        }

        solve( temp, mp);

        // sort(begin(res), end(res));

        // vector<vector<int>> ans;

        // for (int i = 0; i < res.size(); i++) {
        //     vector<int> check =
        //         res[i]; // Take the current permutation as 'check'

        //     // Skip over duplicates in 'res'
        //     while (i + 1 < res.size() && check == res[i + 1]) {
        //         i++;
        //     }

        //     ans.push_back(check); // Add the unique permutation to 'ans'
        // }

        // // Return the result containing only unique permutations
        return res;
    }
};