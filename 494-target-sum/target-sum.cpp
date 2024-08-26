class Solution {
public:
    
    vector<vector<int>> dp;

    // int solve1(int i , vector<int>& nums , int n , int sum){

    //     if(i>=n){
    //         if(sum == 0){
    //           return 1;
    //         } 
    //         return 0;
    //     }
          
    //     int incl = 0;
    //     int excl = 0;

    //     if(nums[i] <= sum){
    //     incl = solve1(i+1 , nums , n , sum-nums[i]) + solve(i+1 , nums , n , sum);
    //     }
    //     else{
    //         excl = solve1(i+1 , nums , n , sum);
    //     }

    //     return incl+excl;
    // }

    int solve2(int i , vector<int>& nums , int n , int sum){

        if(i>=n || sum < 0){
            if(sum == 0){
              return 1;
            } 
            return 0;
        }

        if(dp[i][sum] != -1){
            return dp[i][sum];
        }
          
        int incl = solve2(i+1 , nums , n , sum-nums[i]);
        int excl  = solve2(i+1 , nums , n , sum);
        
        return dp[i][sum] = incl+excl;
    }


    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n = nums.size();
        int total = accumulate(begin(nums) , end(nums) , 0);

        if((total+target)%2 == 1 || total < target || (total+target) < 0){
            return 0;
        }
         
        int sum = (total+target)/2;
        dp = vector<vector<int>> (n+1 , vector<int>(sum+1 , -1));
        return solve2(0 , nums , n , sum);
    }
};