class Solution {
public:

    int n;

    void solve(int i , vector<int>& nums, int &xor_val, int curr){

        if(i >= n){
           xor_val += curr;
           return;
        }
        
        solve(i+1 , nums , xor_val , curr^nums[i]);

        solve(i+1 , nums, xor_val , curr);

        return;
    }

    int subsetXORSum(vector<int>& nums) {

        n = nums.size();
        int xor_val = 0;
        int curr = 0;
    
        solve(0 , nums , xor_val , curr);

        return xor_val;
    }
};