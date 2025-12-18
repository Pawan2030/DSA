class Solution {
public:
    
    int t[2501][2501];

    int solve(int i , int prev , int n , vector<int>& nums){

        if(i >= n) return 0;

        if(prev != -1 && t[i][prev] != -1) return t[i][prev];

        int take = 0;
        if(prev == -1 || nums[prev] < nums[i]){
            take = 1 + solve(i+1 , i , n , nums);
        }

        int skip = solve(i+1 , prev , n , nums);
        
        if(prev != -1){
            return t[i][prev] =  max(take , skip);
        }

        return max(take , skip);
    }



    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();
        memset(t , -1 ,sizeof(t));
        return solve(0 , -1 , n , nums); 
    }
};