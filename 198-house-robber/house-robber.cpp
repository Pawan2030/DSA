class Solution {
public:
    int n;
    
    int solve(int i, vector<int> & nums, vector<int> &dp){

        if(i >= nums.size()){
            return 0;
        }

        if(dp[i] != -1){
            return dp[i];
        }

        int take = nums[i] + solve(i+2, nums, dp);
        int skip = solve(i+1, nums, dp);

        return dp[i] = max(take, skip);
    }

    
    int solveTab(vector<int> &nums){
       
       vector<int> t(n+1, 0);
       t[n] = nums[n-1];

       for(int i=n-1; i>=0; i--){
          
          int take = 0;

          
            take = i+2 < n ? nums[i] + t[i+2]  : nums[i];
          
          
           int skip = t[i+1];
           t[i] = max(take, skip);
       }
        
        return t[0];
    }


    int rob(vector<int>& nums) {
        n = nums.size();
        vector<int> dp(n+1, -1);
        return solveTab(nums);  
    }
};