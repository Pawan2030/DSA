class Solution {
public:

    int numberOfSubarrays(vector<int>& nums, int k) {

        unordered_map<int , int> mp;
        int odd = 0;
        mp[odd]++;
        int n = nums.size();
        int cnt = 0;

        for(int i=0; i<n; i++){
            
            if(nums[i] % 2 != 0){
                odd++;
            }

            if(mp.find(odd - k) != mp.end()){
                cnt += mp[odd-k];
            }

            mp[odd]++;
        }

        return cnt;
        
    }
};