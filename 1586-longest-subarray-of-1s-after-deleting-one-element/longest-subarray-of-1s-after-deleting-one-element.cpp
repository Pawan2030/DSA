class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxOnes = 0;
        int k = 1;
        int n = nums.size();
        int i=0;
        int j=0;
        int cnt = 0; // count for Zero

        while(j < n){

            if(nums[j] == 0){
                cnt++;
            }

            while(i <= j && cnt > k){

                if(nums[i] == 0){
                    cnt--;
                }
                i++;
            }

            maxOnes = max(maxOnes , j-i+1);   
        
            j++;

        }

        return maxOnes-1;
    }
};