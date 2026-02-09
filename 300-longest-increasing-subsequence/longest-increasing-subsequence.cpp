class Solution {
public:
    
    int solve(int idx, int prev, vector<int>& nums, int n,  vector<vector<int>>& dp){
         
         // base case
         if(idx == n){
            return 0;
         }

         if(dp[idx][prev+1] != -1){
            return dp[idx][prev+1];
         }

         //logic
         int take = 0;
         if(prev == -1 || nums[prev] < nums[idx]){
             take = 1 + solve(idx+1, idx, nums, n, dp);
         }

         int skip = solve(idx+1, prev, nums, n, dp);
      
         return dp[idx][prev+1] = max(take,skip);
    }

    int Tabulation(vector<int>& nums, int n){
        
        vector<int> dp(n,1);
        int maxLIS = 1;

        for(int i=0; i<n; i++){
          
          for(int j=0; j<i; j++){
        
             if(nums[j] < nums[i]){
                 dp[i] = max(dp[i] , 1 + dp[j]);
                 //cout<<"big --  "<<dp[i]<<endl;
             }
             
             maxLIS = max(maxLIS , dp[i]);
          }
        }
        return maxLIS;
    }
     

    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();
        //vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        //return solve(0, -1, nums, n, dp);
        return Tabulation(nums,n);
    }
};