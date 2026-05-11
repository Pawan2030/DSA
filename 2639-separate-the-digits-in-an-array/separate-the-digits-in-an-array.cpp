class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans;

        for(int i=0; i<n; i++){

            string st = to_string(nums[i]);
            //ch-'a' = 3
            for(char &ch : st){
                ans.push_back(ch - '0');
            }
        }
        return ans;
    }
};