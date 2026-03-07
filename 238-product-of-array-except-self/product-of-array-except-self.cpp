class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> prefix(n , 1);
        vector<int> res(n);
        
        long long val = 1;

        for(int i=1; i<n; i++){
            
            val *= nums[i-1];
            prefix[i] = val;
        }

        val = 1;
        for(int i=n-1; i>=0; i--){
            res[i] = prefix[i]*val;
            val *= nums[i];
        }

        return res;
    }
};