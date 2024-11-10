class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size(), ans = INT_MAX;
        
        vector<int> f(64);
        
        for(int i = 0, j = 0, cnt = 0; i < n; i++) {
            cnt |= nums[i];
            
            for(int bit = 0; bit < 32; bit++) {
                if(nums[i] & (1 << bit)) {
                    ++f[bit];
                }
            }
            
            while(cnt >= k && j <= i) {
                ans = min(ans, i - j + 1);
                for(int bit = 0; bit < 32; bit++) {
                    if(nums[j] & (1 << bit)) {
                        if(--f[bit] == 0) cnt ^= (1 << bit);
                    }
                }
                j++;
            }
            
        }
        return ans == INT_MAX ? -1 : ans;
    }
};