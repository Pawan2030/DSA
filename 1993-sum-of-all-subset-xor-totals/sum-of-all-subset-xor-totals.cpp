class Solution {
public:

    int n;

    void solve(int i , vector<int>& nums , vector<vector<int>> &ans, vector<int>& vec){

        if(i == n){
            ans.push_back(vec);
            return;
        }
        
        vec.push_back(nums[i]);
        solve(i+1 , nums , ans , vec);

        vec.pop_back();
        solve(i+1 , nums , ans , vec);

        return;
    }

    int subsetXORSum(vector<int>& nums) {

        n = nums.size();
        vector<vector<int>> ans;
        vector<int> vec;

        solve(0 , nums , ans , vec);

        int sum = 0;

        for(auto &arr : ans){
            
            int xor_val = 0;

            for(int &num : arr){
                xor_val ^= num;
            }

            sum += xor_val;
        }

        return sum;
    }
};