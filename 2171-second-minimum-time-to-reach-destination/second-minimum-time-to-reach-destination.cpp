class Solution {
public:

    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {

        vector<int> mini1(n+1 , INT_MAX);
        vector<int> mini2(n+1 , INT_MAX);
        mini1[1] = 0;
        
        unordered_map<int , vector<vector<int>>> adj;  // u -> v => w;
        
        for(auto edge : edges){

            int u = edge[0];
            int v = edge[1];
            adj[u].push_back({v , time});
            adj[v].push_back({u , time});
        }

        //priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> q;
        queue<pair<int,int>> q;
        q.push({0 , 1}); // {time , node}
       
        while(!q.empty()){

            auto top = q.front();
            int    w = top.first;
            int    u = top.second;
            q.pop();

           // if(u == n && mini2[n] != INT_MAX) return mini2[n];
 
            int mode = w/change;

            if(mode%2 == 1){
                w = (mode+1)*change;
            }

            for(auto &it : adj[u]){

                int v = it[0];
                int d = it[1];
               
                if(w + d < mini1[v]){
                    mini2[v] = mini1[v];
                    mini1[v] = w+d;
                    q.push({w+d , v});
                }
                else if(w + d > mini1[v] && w+d < mini2[v]){
                    mini2[v] = w+d;
                    q.push({w+d , v});
                }
            }
            
        }
        return mini2[n];  
    }
};