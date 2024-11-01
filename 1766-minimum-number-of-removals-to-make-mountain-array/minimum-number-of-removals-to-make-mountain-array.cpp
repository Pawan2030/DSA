class Solution {
public:
    
    int n;

    void findmaxLIS(vector<int>& maxLIS , vector<int> &nums){

        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[j] < nums[i]){
                    maxLIS[i] = max(maxLIS[i] , maxLIS[j] + 1);
                }
            }
        }
    }

      void findmaxLDS(vector<int>& maxLDS , vector<int> &nums){

        for(int i=n-1; i>=0; i--){
            for(int j=n-1; j > i; j--){
                if(nums[j] < nums[i]){
                    maxLDS[i] = max(maxLDS[i] , maxLDS[j] + 1);
                }
            }
        }
    }

    int minimumMountainRemovals(vector<int>& nums) {

      n = nums.size();
      vector<int> maxLIS(n , 1);
      findmaxLIS(maxLIS , nums); 
      vector<int> maxLDS(n , 1);
      findmaxLDS(maxLDS , nums);   
      
      int res = n;

      for(int i=0; i<n; i++){
         if(maxLIS[i] > 1 && maxLDS[i] > 1)
            res = min(res , n - maxLIS[i] - maxLDS[i] + 1);
      }
      return res;
    }
};