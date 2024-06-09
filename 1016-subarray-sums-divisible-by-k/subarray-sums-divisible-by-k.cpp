class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        int n = nums.size();
        unordered_map<int,int> mp;
        mp[0]++;

        int cnt = 0;

        //prefix sum

        for(int i=0; i<n; i++){

            nums[i] =  (i == 0) ? nums[i] : ( nums[i] + nums[i-1]);

            int mod = nums[i] % k;

            if(mod < 0){
                mod += k;
            }

            cnt += mp[mod];

            mp[mod]++;
        }

        return cnt;
    }
};