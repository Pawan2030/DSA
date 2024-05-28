class Solution {
public:


    int specialArray(vector<int>& nums) {

        int n = nums.size();

        sort(nums.begin() , nums.end());
       
        for(int x = 0; x<=100; x++){

            int lower = lower_bound(nums.begin() , nums.end() , x) - nums.begin();

            int cnt = n - lower;
               
            if(x == cnt){
                 return x;
             }
        }

        return -1;
    }
};