class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        //sort
        //count
        //if count >= k
        //put in res arr and return res;

        int n = nums.size();
       // sort(begin(nums) , end(nums));
       unordered_map<int,int> mp;
        vector<int> res;
        priority_queue<pair<int,int>> pq;

        for(int &num : nums){
            mp[num]++;
        }

        for(auto &it : mp){
            pq.push({it.second , it.first});
        }

        while(k--){
            res.push_back(pq.top().second);
            //cout<<pq.top().first<< " - " << pq.top().second << endl;
            pq.pop();
        }

        return res;
    }
};