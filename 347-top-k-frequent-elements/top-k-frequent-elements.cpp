class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        //sort
        //count
        //if count >= k
        //put in res arr and return res;

        int n = nums.size();
        sort(begin(nums) , end(nums));
        vector<int> res;
        priority_queue<pair<int,int>> pq;
        int i = 0;

        while(i < n){

            int count = 0;
            int num = nums[i];
            while(i < n && num == nums[i]){
               count++;
               i++;
            }

            pq.push({count , num});
        }

        while(k--){
            res.push_back(pq.top().second);
            //cout<<pq.top().first<< " - " << pq.top().second << endl;
            pq.pop();
        }

        return res;
    }
};