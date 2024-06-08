class Solution {
public:

    bool checkSubarraySum(vector<int>& nums, int k) {
       
       //size
       int n = nums.size();
       
       //finding prefix sum
       for(int i=1; i<n; i++){
          nums[i] = nums[i]+nums[i-1];
       }  

       //let's start to note index and with it MOD track through mapping
       unordered_map<int , int> mp;
       mp[0] = 0;

       for(int i=0; i<n; i++){
          
          int mod_val = nums[i]%k;

          if(mp.find(mod_val) != mp.end()){
               
               int idx_diff = (i+1) - mp[mod_val];

               if(idx_diff >= 2){
                  return true;
               }
          }
          else{
            mp[mod_val] = i+1;
          }

       }
        
        return false;
    }
};