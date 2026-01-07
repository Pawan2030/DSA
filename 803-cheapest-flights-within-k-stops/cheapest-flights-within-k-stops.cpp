class Solution {
public:

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        // lets prep the adj list
        unordered_map<int, vector<pair<int,int>>> adj;

        for(auto it : flights){

            int s = it[0];
            int d = it[1];
            int p = it[2];

            adj[s].push_back({d , p});
        }

        vector<int> dist(n , INT_MAX); // price , num of station
        //  k(num of station) - stop -price
        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>> pq;
        dist[src] = 0;
        pq.push({0 , {src , 0 } });

        while(!pq.empty()){

            auto it = pq.top();
            pq.pop();

            int stop  = it.first;
            int u     = it.second.first;
            int p     = it.second.second;

            if(stop > k) continue;

            for(auto ngr : adj[u]){

                int node  = ngr.first;
                int price = ngr.second;

                if(p + price < dist[node] && stop <= k){
                    dist[node] = p + price;
                    pq.push({stop+1 , { node , p + price}});
                }
            }

        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};