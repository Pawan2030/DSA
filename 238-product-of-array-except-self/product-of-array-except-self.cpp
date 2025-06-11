class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> left(n);
        // vector<int> right(n);
        left[0] = 1;
        // right[n-1] = 1;

        for(int i=1; i<n; i++){
           left[i] = left[i-1]*nums[i-1];
        }

        // for(int i=n-2; i>=0; i--){
        //     right[i] = right[i+1]*nums[i+1];
        // }
        
        vector<int> res(n);
        res[n-1] = left[n-1];
        int mul = nums[n-1];

        for(int i=n-2; i>=0; i--){
            res[i] = mul*left[i];
            mul *= nums[i];
        }

        return res;
    }
};