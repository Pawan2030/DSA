class Solution {
public:
    int minDifference(vector<int>& nums) {

        int n = nums.size();
        int res = INT_MAX;

        if(n <= 3){
            return 0;
        }

        sort(begin(nums) , end(nums));

        //1-> last three

        int mini = nums[0];
        int maxi = nums[n-4];

        res = min(res , maxi-mini);

        //2-> second 
        mini = nums[3]; 
        maxi = nums[n-1];
        res = min(res , maxi-mini);

        //3-> 2 aage vale
        mini = nums[2]; 
        maxi = nums[n-2];
        res = min(res , maxi-mini);

        //4-> 2 peeche vale
        mini = nums[1]; 
        maxi = nums[n-3];
        res = min(res , maxi-mini);

        return res;
    }
};