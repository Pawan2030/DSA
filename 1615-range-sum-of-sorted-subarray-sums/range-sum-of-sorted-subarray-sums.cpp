class Solution {
public:
    int mod = 1e9+7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {

        int cnt = 1;
        int sum = 0;

        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;

        for(int i=0; i<n; i++){

            pq.push({nums[i] , i});

        }
        
        while(!pq.empty()){

            int val = pq.top().first;
            int idx = pq.top().second;
            pq.pop();
        
            if(cnt >= left && cnt <= right){
                sum = (sum%mod+ val%mod)%mod;
            }

            if(idx + 1 < n){
                val += nums[idx+1];
                pq.push({val , idx+1});
            }

            if(cnt > right){
                break;
            }

            cnt++;
        }
    
        return sum;
    }
};