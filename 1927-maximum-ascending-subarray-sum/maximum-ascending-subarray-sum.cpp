class Solution {
public:
     
     int n;
     
    void solve(int i, int prev, int &res , int sum , vector<int> &nums){
        
        if(i >= n){
            return;
        }

       
        if(prev == -1 || nums[prev] < nums[i]){
            sum += nums[i];
            res = max(res , sum);
            solve(i+1,i,res,sum,nums);
        }
        else{
            solve(i+1,i,res,nums[i],nums);
        }

     }

    int maxAscendingSum(vector<int>& nums) {
        
        n = nums.size();
        int res = INT_MIN;
        int sum = 0;
        solve(0 , -1 , res , sum , nums);
        return res;
    }
};