class Solution {
public:

    int findPivotIndex(vector<int>& nums){

        int r = nums.size()-1;
        int l = 0;

        while(l < r){

            int mid = (r-l)/2 + l;

            if(nums[mid] > nums[r]){
                l = mid+1;
            }
            else{
                r = mid;
            }
        } 
        return r;
    }

    int BinarySearch(vector<int>& nums, int s , int e , int target){

        while(s <= e){

            int mid = (e-s)/2 + s;

            if(nums[mid] == target){
               return mid;
            }
            else if(nums[mid] < target){
                 s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
        return -1;
    }


    int search(vector<int>& nums, int target) {
        

        int idx = findPivotIndex(nums);

        int i   = BinarySearch(nums , 0 , idx-1 , target);

        if(i != -1) return i;

        
        return BinarySearch(nums , idx , nums.size()-1 , target);

    }
};