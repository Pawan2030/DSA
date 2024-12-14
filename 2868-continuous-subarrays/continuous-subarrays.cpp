class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long res = 0;
        int i = 0, j = 0;
        int n = nums.size();

        // Use a multiset to handle duplicates
        multiset<int> st;

        while (j < n) {
            st.insert(nums[j]);

            // Adjust `i` to maintain the condition `max - min <= 2`
            while (*st.rbegin() - *st.begin() > 2) {
                st.erase(st.find(nums[i])); // Erase one occurrence of nums[i]
                i++;
            }

            // All subarrays between `i` and `j` are valid
            res += (j - i + 1);

            j++;
        }

        return res;
    }
};
