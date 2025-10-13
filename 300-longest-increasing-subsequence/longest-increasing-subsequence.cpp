class Solution {

private: 
    
     int t[2501][2501];

     int solve(int idx, int prev, vector<int>& nums, int n){

        if(n <= idx){
            return 0;
        }

        if(prev != -1 && t[idx][prev] != -1){
            return t[idx][prev];
        }
        
        int take = 0;
        if(prev == -1 || nums[prev] < nums[idx]){
           take = 1 + solve(idx+1, idx, nums, n);
        }

        int s = solve(idx+1, prev, nums, n);

        if(prev != -1){
           return t[idx][prev] = max(take , s);
        }

        return max(take , s);
     }


public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        memset(t, -1, sizeof(t));
        return solve(0 , -1 , nums , n);
    }
};