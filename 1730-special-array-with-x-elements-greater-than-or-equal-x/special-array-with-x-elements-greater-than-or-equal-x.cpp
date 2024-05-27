class Solution {
public:


    int specialArray(vector<int>& nums) {

        int n = nums.size();

        sort(nums.begin() , nums.end());
        int res = -1;

        for(int i = 0; i<=100; i++){
             
             int x = i;
             int cnt = 0;
             int p;

             for(p=0; p<n; p++){
                 
                  if(x <= nums[p]){
                      cnt++;
                  }
             }

             if(x == cnt){
                 res = cnt;
             }
        }

        return res;

    }
};