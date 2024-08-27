class Solution {
public:
    vector<vector<int>> res;
    int n;

    void solve(vector<int>& nums, vector<int> temp, unordered_set<int> st) {

        // base case
        if (temp.size() == n) {
            res.push_back(temp);
            return;
        }

        // logic
        for (int i = 0; i < n; i++) {

            if (st.find(i) == st.end()) {
                temp.push_back(nums[i]);
                st.insert(i);
                solve(nums, temp, st);
                temp.pop_back();
                st.erase(i);
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {

        n = nums.size();
        vector<int> temp;
        unordered_set<int> st;
        solve(nums, temp, st);

        sort(begin(res), end(res));

        vector<vector<int>> ans;

        for (int i = 0; i < res.size(); i++) {
            vector<int> check =
                res[i]; // Take the current permutation as 'check'

            // Skip over duplicates in 'res'
            while (i + 1 < res.size() && check == res[i + 1]) {
                i++;
            }

            ans.push_back(check); // Add the unique permutation to 'ans'
        }

        // Return the result containing only unique permutations
        return ans;
    }
};