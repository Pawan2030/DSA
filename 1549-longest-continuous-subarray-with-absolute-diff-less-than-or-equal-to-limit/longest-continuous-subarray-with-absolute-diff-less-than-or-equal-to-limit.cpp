class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size(), minVal = INT_MAX, res = 1, left, right;
        multiset<int> s;
        left = 0;
        for(int i = 0; i < n; i++){
            s.insert(nums[i]);
            while(true){
                // ptr points to the top element
                auto start = s.begin(); // least element
                auto end = --s.end(); // max element
                if(*end - *start > limit){
                    // remove the left most element
                    auto rem = s.lower_bound(nums[left]);
                    s.erase(rem);
                    left += 1; // Change the window length
                }
                else{
                    break;
                }
            }
            int len = -1;
            len = s.size();
            res = max(res, len);
        }
        return res;
    }
};