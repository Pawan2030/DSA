class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        
        int n = nums.size();
        sort(begin(nums) , end(nums));
        unordered_map<float,float> mp;
        int res = -1;

        for(int num : nums){
            
            float val = sqrt(num);

            if(mp.find(val) != mp.end()){

                int streak = mp[val];
                mp[num] = streak+1;
                res = max(res , streak+1);
            }
            else{
                mp[num] = 1;
            }
        }
        return res;
    }
};