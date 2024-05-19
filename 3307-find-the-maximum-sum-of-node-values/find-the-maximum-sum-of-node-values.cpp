class Solution {
public:


    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        
        long long ans = 0;
        int n = nums.size();
        int mini = INT_MAX;
        
        int cnt = 0;

        for(long long num : nums){
            
            ans += max(num , num^k);

            if((num^k)> num){
                cnt++;
            }

           mini = min((long long)mini , abs(num - (num^k)));
    
        }

        if(cnt % 2 == 0){
            return ans;
        }

         return ans-mini;  
    }
};