class Solution {
public:
    
    int solve(int i , vector<int>& nums , int n , int sum){

        if(i>=n){
            if(sum == 0){
              return 1;
            } 
            return 0;
        }
          
        int incl = 0;
        int excl = 0;

        if(nums[i] <= sum){
          incl = solve(i+1 , nums , n , sum-nums[i]) + solve(i+1 , nums , n , sum);
        }
        else{
            excl = solve(i+1 , nums , n , sum);
        }

        return incl+excl;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n = nums.size();
        int total = accumulate(begin(nums) , end(nums) , 0);

        if((total+target)%2 == 1 || total < target){
            return 0;
        }

        int sum = (total+target)/2;

        return solve(0 , nums , n , sum);
    }
};