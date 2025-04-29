class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {

        int n = nums.size();

        int maxEle = *max_element(nums.begin() , nums.end());
       
        long long NumberOfSubarray = 0;
        long long freq_maxEle = 0;

        int i =0;
        int j = 0;

        while(j < n){

           if(maxEle == nums[j]){
             freq_maxEle++;
           }

            while(freq_maxEle >= k){

                NumberOfSubarray += (n-j);

                if(maxEle == nums[i]){
                    freq_maxEle--;
                }
    
                i++;
            }
            j++;
        }
        return NumberOfSubarray;
    }
};