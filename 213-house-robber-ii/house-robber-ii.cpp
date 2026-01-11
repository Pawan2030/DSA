class Solution {
public:
    
    int n;

    int solve(int i, int n , vector<int>& nums, vector<int>& dp){

        if(i >= n){
            return 0;
        }

        if(dp[i] != -1){
            return dp[i];
        }

        int take = nums[i] + solve(i+2, n, nums,dp);
        int skip =           solve(i+1, n, nums,dp);

        return dp[i] = max(take,skip);
    }

    int rob(vector<int>& nums) {
        n = nums.size();
        if(n == 1) return nums[0];

        vector<int> dp(n+1 , -1);

        int ans = INT_MIN;

        ans = max(ans , solve(0 , n-1 , nums , dp));

        vector<int> t(n+1 , -1);
        ans = max(ans , solve(1 , n   , nums, t));
        return ans;
    }
};