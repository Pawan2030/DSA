class Solution {
public:
    
    #define P pair<int , int>

    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        
        priority_queue<P , vector<P> , greater<P>> pq;
        int n = nums.size();

        for(int i=0; i<n; i++){
            pq.push({nums[i] , i});
        }

        while(k--){

            int top = pq.top().first;
            int idx = pq.top().second;

            pq.pop();

            int val = top*multiplier;
            pq.push({val , idx});
        }

        while(!pq.empty()){

            int val = pq.top().first;
            int idx = pq.top().second;
            pq.pop();
            nums[idx] = val;
        }

        return nums;
    }
};