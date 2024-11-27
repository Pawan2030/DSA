class Solution {
public:

   #define P pair<int,int>
   
   int dij(int n , unordered_map<int , vector<P>>& adj){

        vector<int> res(n , INT_MAX);
        res[0] = 0;
        priority_queue<P , vector<P> , greater<P>> pq;
        pq.push({0 , 0});

        while(!pq.empty()){

            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto &ngr : adj[node]){

                int wt = ngr.second;
                int ngrNode = ngr.first;

                if(dist + wt < res[ngrNode]){
                    pq.push({dist+wt , ngrNode});
                    res[ngrNode] = dist+wt;
                }
            }
        }

        return res[n-1];
   }

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        
        //lets build graph
        unordered_map<int , vector<P>> adj;

        for(int i=0; i<n-1; i++){
            int u = i;
            int v = i+1;
            adj[u].push_back({v , 1});
        }

        vector<int> shortestDistToN;

        for(auto it : queries){

            int u = it[0];
            int v = it[1];

            adj[u].push_back({v , 1});
     
            int shortDist = dij(n , adj);

            shortestDistToN.push_back(shortDist);
        }
        return shortestDistToN;
    }
};