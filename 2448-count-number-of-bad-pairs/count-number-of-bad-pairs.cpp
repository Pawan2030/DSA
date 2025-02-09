class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        
        long long cnt = 0;
        long long n = nums.size();
        unordered_map<long long,long long> mp;

        for(int i = 0; i<n; i++){
           long long val = nums[i]-i;
           if(mp.find(val) != mp.end()){
               cnt += mp[val];
           }

           mp[val]++;
        }

        long long total =  (n*(n-1))/2;
        return total - cnt;
    }
};