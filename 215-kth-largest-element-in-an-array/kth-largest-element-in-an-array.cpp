class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue<int> pq;
        int n = nums.size();

        for(int &num : nums){
            pq.push(num);
        }


        while(k-1 > 0){
           
           int top = pq.top();
           pq.pop();
           k--;
        }

        return pq.top();
    }
};