class Solution {
public:

    int mod = 1e9+7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        
        int size = ( n * (n + 1)) / 2 ;
        vector<int> sum(size , 0);
        //int n = nums.size();
         //sum[0] = nums[0];

        int k = 0;

        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){

                if(i != j){
                    sum[k] = sum[k-1] + nums[j];
                    //cout<<sum[k]<<" , ";
                }
                else{
                    sum[k] = nums[j];
                }
                k++;
            }
        }

        sort(begin(sum) , end(sum));

        for(int i=0; i<size; i++){
           cout<<sum[i]<<" , ";
        }
        
        int ans = 0;
        for(int i=left; i<=right; i++){
            ans = ( ans%mod + sum[i-1])%mod;
        }
        return ans;
    }
};