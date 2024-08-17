class Solution {
public:

    bool solve(vector<int> &nums , int n , int tar){
         
        bool arr[n+1][tar+1];

        //where n = 0
        for(int i=0; i<=tar; i++){
            arr[0][i] = false;
        }

        //where sum = 0
        for(int i=0; i<=n; i++){
            arr[i][0] = true;
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=tar; j++){

                if(nums[i-1] <= j){

                    arr[i][j] = arr[i-1][j] || arr[i-1][j-nums[i-1]];
                }
                else{
                    arr[i][j] = arr[i-1][j];
                }

            }
        }

       return arr[n][tar];
    }

    
    // bool solve(int i , vector<int>& nums , int tar , int sum , int n){

    //     if(sum == tar){
    //         return true;
    //     }

    //     if(i >= n) return false;

    //     if(sum + nums[i] <= tar){

    //         bool res = solve(i+1 , nums , tar , sum+nums[i] , n);
    //         bool ress = solve(i+1 , nums , tar , sum , n);

    //         if(res || ress) return true;
    //     }
    //     else{
    //         bool resss = solve(i+1 , nums , tar , sum , n);

    //         if(resss) return true;
    //     }

    //     return false;
    // }

    bool canPartition(vector<int>& nums) {

        int tar = 0;
        int n = nums.size();
        tar = accumulate(begin(nums) , end(nums) , 0);

        if(tar%2 == 1 || n == 1){
            return false;
        }

        tar /= 2;

       
        return solve( nums , n ,  tar);  
    }
};