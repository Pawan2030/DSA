class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int maxOnes = 0;
        int n = nums.size();
        int i=0;
        int j=0;
        int cnt = 0; // count for Zero

        while(j < n){

            while(i < j && cnt > k){

                if(nums[i] == 0){
                    cnt--;
                }
                i++;
            }

            //maxOnes = max(maxOnes , j-i); 
            
            if(nums[j] == 0){
                cnt++;
            }
            j++;

            if(cnt <= k){
               maxOnes = max(maxOnes , j-i); 
            }
        }

        return maxOnes;
    }
};