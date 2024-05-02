class Solution {
public:

    int findMaxK(vector<int>& nums) {

        unordered_map<int,int> mp;
        int ans = -1;

        for(int &num : nums){
            mp[num]++;
        }
 

        int maxi = INT_MIN;

        for(int i=0; i<nums.size(); i++){
            
           int nage = -nums[i];

           if(maxi < nums[i] && mp.find(nage) != mp.end()){
               maxi = nums[i];
               ans = maxi;
           }
        }
        return ans;
    }
};