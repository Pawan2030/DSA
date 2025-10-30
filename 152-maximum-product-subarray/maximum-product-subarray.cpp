class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //frute force
        
        int n = nums.size();
        int maxi = INT_MIN;

        for(int i=0; i<n; i++){

            int temp = 1;

            for(int j=i; j<n; j++){
                 temp *= nums[j];
                 maxi = max(maxi , temp);
            }
        }

        return maxi;
    }
};