class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        
        long long res = 0;
        int i = 0 , j = 0;
        int n = nums.size();

        //set for maintaining max and min
        multiset<int> mp;

        while(j < n){

            mp.insert(nums[j]);

            while(*mp.rbegin() - *mp.begin() > 2){
                mp.erase(mp.find(nums[i]));
                i++;
            }

            res += (j - i + 1);
            j++;
        }
        return res;
    }
};