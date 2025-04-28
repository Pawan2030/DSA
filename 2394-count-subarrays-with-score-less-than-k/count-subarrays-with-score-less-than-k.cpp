class Solution {
public:

    long long countSubarrays(vector<int>& nums, long long k) {

        int i = 0;
        int j = 0;
        int n = nums.size();
        long long int cnt = 0;
        long long int sum = 0;


        while(j < n){
            
            sum += nums[j];

            while(sum * (j-i+1) >= k){ 
                sum -= nums[i];
                i++;
            }
              
            cnt += (j-i+1);
            j++;
        }
        return cnt;
    }
};