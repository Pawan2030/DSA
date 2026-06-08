class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        
        int n = nums.size();
        queue<int> q1;
        queue<int> q2;
        int count = 0;

        for(int i=0; i<n; i++){

            if(nums[i] > pivot){
                q1.push(nums[i]);
            }
            else if(nums[i] < pivot){
                q2.push(nums[i]);
            }
            else{
                count++;
            }
        }

        while(count--){
            q2.push(pivot);
        }
        
        vector<int> ans;

        while(!q2.empty()){
           ans.push_back(q2.front());
           q2.pop();
        }

        while(!q1.empty()){
           ans.push_back(q1.front());
           q1.pop();
        }

        return ans;
    }
};