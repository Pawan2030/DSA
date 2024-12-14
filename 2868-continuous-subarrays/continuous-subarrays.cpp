class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        
        long long res = 0;
        int i = 0 , j = 0;
        int n = nums.size();

        //set for maintaining max and min
        map<int,int> mp;

        while(j < n){

            mp[nums[j]]++;

            while(mp.rbegin()->first - mp.begin()->first < 0 || mp.rbegin()->first - mp.begin()->first > 2){
                mp[nums[i]] -= 1;
                if(mp[nums[i]] == 0){
                    mp.erase(nums[i]);
                }
                i++;
               // cout<<j<<endl;
            }

            int mini = mp.begin()->first;
            int maxi = mp.rbegin()->first;

            if(abs(maxi-mini) >= 0 && abs(maxi-mini) <= 2){
                res += (j - i + 1);
            }

            j++;
        }
        return res;
    }
};