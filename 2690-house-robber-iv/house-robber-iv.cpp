class Solution {
public:

    bool isPossible(int mid ,vector<int>& nums, int k){

        for(int i=0; i<nums.size(); i++){

            if(nums[i] <= mid){
               k--;
               i++;
            }

            if(k == 0) return true;
        }
        
        return false;
    }

    int minCapability(vector<int>& nums, int k) {
        
        int n = nums.size();
        int s = INT_MAX;
        int e = INT_MIN;

        for(int num : nums){
            s = min(s , num);
            e = max(e , num);
        }
        
        int res = 0;

        while(s <= e){
            
            int mid = s + (e-s)/2;

            if(isPossible(mid , nums , k)){
                res = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }

        return res;
    }
};