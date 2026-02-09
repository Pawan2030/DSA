class Solution {
public:
    
    int solve(int idx, int prev, vector<int>& nums, int n,  vector<vector<int>>& dp){
         
         // base case
         if(idx == n){
            return 0;
         }

         if(prev != -1 && dp[idx][prev] != -1){
            return dp[idx][prev];
         }

         //logic
         int take = 0;
         if(prev == -1 || nums[prev] < nums[idx]){
             take = 1 + solve(idx+1, idx, nums, n, dp);
         }

         int skip = solve(idx+1, prev, nums, n, dp);
         
         if(prev != -1){
            dp[idx][prev] = max(take,skip);
         }
         
         return max(take,skip);
    }
     

    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(0, -1, nums, n, dp);
    }
};