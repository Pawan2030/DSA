class Solution {
public:

    int findPivot(vector<int>& nums){

        int n = nums.size();

        int i = 0;
        int j = n-1;

        while(i < j){

            int mid = i + (j-i)/2;

            if(nums[mid] > nums[j]){
                i = mid+1;
            }
            else{
                j = mid;
            }
        }
        return i;
    }

    int solve(vector<int>& nums , int s , int e, int tar){

        int n = nums.size();

        while(s <= e){

            int mid = s + (e-s)/2;

            if(nums[mid] == tar){
                return mid;
            }
            else if(nums[mid] < tar){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }

        return -1;
    }

    int search(vector<int>& nums, int target) {
        
        int n = nums.size();
        int idx = findPivot(nums);

        int l = solve(nums , 0 , idx-1 , target);
        int r = solve(nums , idx , n-1 , target);

        if(l != -1) return l;
        return r;
    }
};