class Solution {
public:
    
    int n;

    void solve(int i, vector<int>& nums , vector<int> temp , vector<vector<int>>& ans){

        //base case
        if(i == n){
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[i]);
        solve(i+1 , nums ,temp, ans);

        temp.pop_back();
        solve(i+1 , nums , temp , ans);

        return;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        
        n = nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0 , nums , temp, ans);

        return ans;
    }
};