class Solution {
public:
    
    void Dijsktra(int s , int k , unordered_map<int , vector<vector<int>>>& adj , vector<int>& miniCost){
        
        //priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>> pq;
        queue<pair<int,pair<int,int>>> pq;
        pq.push({0 , {0 , s}}); //cost -> stop, station
      

        while(!pq.empty()){
            
            int w    = pq.front().first;
            int stop = pq.front().second.first;
            int u    = pq.front().second.second;
            pq.pop();

            if(stop > k) continue;

            for(auto &ngr : adj[u]){

            int node = ngr[0];
            int    d = ngr[1];

            if(w+d < miniCost[node] && stop <= k){
                miniCost[node] = w+d;
                pq.push({w+d , {stop+1 , node}});
            }
        }

    }
}

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<int> miniCost(n , INT_MAX);
        miniCost[src] = 0;

        unordered_map<int , vector<vector<int>>> adj;

        for(auto &fly : flights){

            int u = fly[0];
            int v = fly[1];
            int w = fly[2];

            adj[u].push_back({v , w});
        }

        Dijsktra(src , k , adj , miniCost);

        for(int i =0; i<n; i++){
            cout<<i<<"-> "<<miniCost[i]<<endl;
        }

        return miniCost[dst] != INT_MAX ? miniCost[dst] : -1;

    }
};