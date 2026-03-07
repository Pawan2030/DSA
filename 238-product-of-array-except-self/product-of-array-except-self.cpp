class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> prefix(n , 1);
        vector<int> sufix(n,1);
        vector<int> res(n);
        
        long long val = 1;

        for(int i=1; i<n; i++){
            
            val *= nums[i-1];
            prefix[i] = val;
        }

        val = 1;
        for(int i=n-2; i>=0; i--){
            val *= nums[i+1];
            sufix[i] = val;
        }

        for(int i=0; i<n; i++){
            res[i] = prefix[i]*sufix[i];
        }

        return res;
    }
};