class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

        unordered_set<int> st;
        int n = nums.size();
        long long res = 0;
        long long sum = 0;

        int i=0, j=0;

        // while(j < k){

        //     sum += nums[j];
        //     st.insert(nums[j]);
        //     j++;
        // } 

        // if(st.size() == k){
        //     res = max(res , sum);
        // }

        while(j < n){

            while(st.count(nums[j])){
                sum -= nums[i];
                st.erase(nums[i]);
                i++;
            }

            sum += nums[j];
            st.insert(nums[j]);
        
            if(k == (j-i+1)){

                res = max(res , sum);

                sum -= nums[i];
                st.erase(nums[i]);
                i++;
            }
            
            j++;
        }

        return res;
    }
};