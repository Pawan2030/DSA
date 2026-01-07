class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        //lets prep the adj list first

        unordered_map<int , vector<pair<int,int>>> adj;

        for(auto time : times){

            int u = time[0];
            int v = time[1];
            int t = time[2];
            adj[u].push_back({v , t});
        }

        vector<int> dist(n+1, INT_MAX);
        priority_queue<pair<int,int> ,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0 , k});
        dist[k] = 0;
        dist[0] = 0;

        while(!pq.empty()){

            auto it = pq.top();
            pq.pop();

            int time = it.first;
            int u = it.second;

            for(auto ngr : adj[u]){

                int v = ngr.first;
                int t = ngr.second;

                if(t + time < dist[v]){
                    dist[v] = t + time;
                    pq.push({t+time , v});
                }
            }
        }

        int ans = INT_MIN;

        for(int time : dist){
            ans = max(ans , time);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};