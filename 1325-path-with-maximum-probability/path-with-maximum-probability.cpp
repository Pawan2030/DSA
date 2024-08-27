class Solution {
public:

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        
        unordered_map<int  , vector<pair<int,double>>> adj;

        for(int i=0; i<edges.size(); i++){

            int u = edges[i][0];
            int v = edges[i][1];
            double w = succProb[i];

            adj[u].push_back({v , w});
            adj[v].push_back({u , w});
        }

        vector<double> dist(n , INT_MIN);
        dist[start_node] = 1;
        priority_queue<pair<double , int>> q;
        q.push({1 , start_node});

        while(!q.empty()){

         auto top = q.top();
         q.pop();

         double d = top.first;
         int node = top.second;

         for(auto ngr : adj[node]){

            int next = ngr.first;
            double w = ngr.second;

            if(dist[next] < w*d){
                dist[next] = w*d;
                q.push({w*d , next}); 
            }

         } 

        }
        
        if(dist[end_node] == INT_MIN){
            return 0;
        }

        return dist[end_node];
    }
};