class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ksum(n - k + 1);
        vector<int> dp1(n - k + 1), dp2(n - k + 1);
        vector<int> result(3);
        
        int temp = 0;
        for (int i = 0; i < k; i++) {
            temp += nums[i];
        }
        ksum[0] = temp;
        
        for (int i = 1; i <= n - k; i++) {
            ksum[i] = ksum[i - 1] + nums[i + k - 1] - nums[i - 1];
        }
        
        dp1[0] = 0;
        for (int i = 1; i <= n - k; i++) {
            dp1[i] = (ksum[i] > ksum[dp1[i - 1]]) ? i : dp1[i - 1];
        }
        
        dp2[n - k] = n - k;
        for (int i = n - k - 1; i >= 0; i--) {
            dp2[i] = (ksum[i] >= ksum[dp2[i + 1]]) ? i : dp2[i + 1];
        }
        
        int maxi = INT_MIN;
        for (int i = k; i <= n - 2 * k; i++) {
            int sum = ksum[dp1[i - k]] + ksum[i] + ksum[dp2[i + k]];
            if (sum > maxi) {
                maxi = sum;
                result = {dp1[i - k], i, dp2[i + k]};
            }
        }
        
        return result;
    }
};