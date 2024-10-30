class Solution {
public:
    
    int n;
    int dp[2501][2501];

    int solve(int i , int prev , vector<int>& nums){
      
      if(i >= n){
         return 0;
      }

      if(prev != -1 && dp[i][prev] != -1) return dp[i][prev];
       
      int take = 0;
      if(prev == -1 || nums[prev] < nums[i]){
         take = 1 + solve(i+1 , i , nums); 
      }

      int skip = solve(i+1 , prev , nums);
      
      if(prev != -1)
        dp[i][prev] = max(take , skip); 

      return max(take , skip);

    }

    int lengthOfLIS(vector<int>& nums) {
        
        n = nums.size();
        memset(dp , -1 , sizeof(dp));
        //index , prev_ele_idx , vector
        return solve(0 , -1 , nums);  
    }
};