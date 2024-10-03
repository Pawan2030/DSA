class Solution {
public:

    int minSubarray(vector<int>& nums, int p) {
        
        int n = nums.size();

        int sum = 0;

        for(int num : nums){
            sum = (sum + num)%p;
        }

        if(sum%p == 0){
            return 0;
        }

        int tar = sum%p;
        unordered_map<int,int> mp;
        mp[0] = -1;
        int curr = 0;
        int res = n;

        for(int i = 0; i<n; i++){

            curr = (curr + nums[i])%p;

            if(mp.find((curr-tar+p)%p) != mp.end()){
                res = min(res , i - mp[(curr-tar+p)%p]);
            }

            mp[curr%p] = i;
        }

        return res == n ? -1 : res;
    }
};