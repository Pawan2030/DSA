class Solution {
public:
    int n;

    void solve(int i, int prev, int &res, int sum, vector<int> &nums) {
        if (i >= n) {
         // Fix: Ensure result updates when reaching the end
            return;
        }
         
          
        // Continue the ascending subarray
        if (prev == -1 || nums[prev] < nums[i]) {
            sum += nums[i];
            res = max(res, sum);
            solve(i + 1, i, res, sum, nums);
        }
        else
        // Start a new subarray from the current index
        solve(i + 1, i, res, nums[i], nums);
    }

    int maxAscendingSum(vector<int>& nums) {
        n = nums.size();
        int res = 0; // Fix: Start from 0 instead of INT_MIN
        solve(0, -1, res, 0, nums);
        return res;
    }
};
