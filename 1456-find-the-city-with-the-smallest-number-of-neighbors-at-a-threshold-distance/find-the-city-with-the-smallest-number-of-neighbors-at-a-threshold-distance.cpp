class Solution {
public:
    
    //#define P pair<int , int>
    typedef pair<int,int> P;

    void fill_result_ShortestDist(int s , unordered_map<int , vector<vector<int>>>& adj , vector<int>& res){
       
        priority_queue<P , vector<P> , greater<P>> pq;
        pq.push({0 , s});

        while(!pq.empty()){

            int w    = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto &vec : adj[node]){

                int v = vec[0];
                int d = vec[1];

                if(d + w < res[v]){
                    res[v] = w+d;
                    pq.push({d+w , v});
                }
            }

        }
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        unordered_map<int , vector<vector<int>>> adj;

        for(auto &edge : edges){

            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({v , w});
            adj[v].push_back({u , w});
        }

        int leastReachableCity = -1;
        int leastCount = INT_MAX;

        for(int i = 0; i<n; i++){

            vector<int> result(n , INT_MAX);
            result[i] = 0;

            fill_result_ShortestDist(i , adj , result);

            int count = 0;

            for(int j = 0; j<n; j++){

                if(result[j] <= distanceThreshold){
                    count++;
                }
            }

            if(count-1 <= leastCount){
                leastCount         = count-1;
                leastReachableCity = i;
            }

        }

        return leastReachableCity;
    }
};