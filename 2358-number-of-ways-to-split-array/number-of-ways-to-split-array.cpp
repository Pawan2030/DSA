class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {

        int n = nums.size();
        vector<long long int> sum(n , 0);
        sum[0] = nums[0];

        for(int i=1; i<n; i++){
            sum[i] = sum[i-1] + nums[i];
        }  

        int way = 0;

        for(int i=0; i<n-1; i++){

            long long int left  = sum[i];
            long long int right = sum[n-1]-sum[i];

            if(left >= right){
                way++;
            }
        }
        return way;
    }
};