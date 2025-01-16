class Solution {
public:
    
    int n;
    int dp[201][10001];

    bool solve(int i, int tar, vector<int>& nums){

        if(tar == 0){
            return true;
        }

        if(i >= n || tar < 0) return false;

        if(dp[i][tar] != -1){
            return dp[i][tar];
        }

        bool take = solve(i+1, tar-nums[i], nums);
        if(take) return dp[i][tar] = true;

        bool skip = solve(i+1, tar, nums);

        return dp[i][tar] = take || skip;

    }

    bool canPartition(vector<int>& nums) {
        
        n = nums.size();
        int sum = 0;
        memset(dp , -1, sizeof(dp));

        for(int num : nums){
            sum += num;
        }

        if(sum%2 != 0) return false;

        return solve(0, sum/2, nums);
        
    }
};