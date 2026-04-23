class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n = nums.size();
        sort(nums.begin() , nums.end());
        vector<vector<int>> res;

        for(int i=0; i<n; i++){
           
           if(i>0 && nums[i-1] == nums[i]) continue;

           int j = i+1;
           int k = n-1;
           int tar = -nums[i];


           while(j < k){
             
             if(tar == nums[j] + nums[k]){
                 res.push_back({nums[i] , nums[j] , nums[k]});
                 j++;
                 k--;

                 while(j < k && nums[j-1] == nums[j]){
                    j++;
                 }

                 while(j<k && nums[k] == nums[k+1]){
                    k--;
                 }
             }
             else if(nums[j] + nums[k] > tar){
                 k--;
             }
             else{
                j++;
             }
           }
        }
        return res;
    }
};