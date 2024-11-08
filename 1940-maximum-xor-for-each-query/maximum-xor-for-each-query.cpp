#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        int mask = (1 << maximumBit) - 1;  // This is 2^maximumBit - 1
        vector<int> res(n);

        // Calculate initial cumulative XOR of all elements in nums
        int cumulativeXor = 0;
        for (int num : nums) {
            cumulativeXor ^= num;
        }

        // Calculate the result for each query
        for (int i = 0; i < n; ++i) {
            res[i] = cumulativeXor ^ mask;  // Get the max XOR value
            cumulativeXor ^= nums[n - 1 - i];  // Remove the last element in the current cumulative XOR
        }

        return res;
    }
};
