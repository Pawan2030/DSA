class Solution {
public:

    long long maximumSubarraySum(vector<int>& nums, int k) {
        
        long long sum = 0;
        long long res = 0;
        int n  = nums.size();
        int unique = 0;

        unordered_map<int,int> mp;
        int i=0;
        int j=0;

        while(j < k){
           int ele = nums[j];
           mp[ele]++;

           if(mp[ele] == 1){
             unique++;
           }
           sum += ele;
           j++;
        }
        
        if(unique == k)
         res = max(res , sum);

        while(j < n){

            mp[nums[j]]++;

            if(mp[nums[j]] == 1){
                unique++;
            }

            sum += nums[j];
            sum -= nums[i];

            if(mp[nums[i]] == 1){
               unique -= 1;
            }
            
            mp[nums[i]]--;
            i++;

            if(unique == k){
                res = max(res , sum);
            }

            j++;
        }

        return res;
    }
};