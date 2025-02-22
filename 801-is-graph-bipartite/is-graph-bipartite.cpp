class Solution {
public:
   
    bool bfs(int u , vector<bool>& visited, vector<vector<int>>& graph){
        
        int n = graph.size();
        vector<int> cnt(n);
        queue<pair<int,pair<int,int>>> q; // {node, {parent, level}}

        q.push({u,{-1 , 0}});
        visited[u] = true;
        cnt[u] = 0;  // Fix: Assign cnt[u] instead of cnt[0]
       
        while(!q.empty()){

            int v = q.front().first;
            int p = q.front().second.first;
            int till = q.front().second.second;
            q.pop();

            for(int &ngr : graph[v]){

                if(ngr == p) continue;

                if(visited[ngr]){

                    if((cnt[v] - cnt[ngr]+1) % 2 != 0){  // Fix: Use cnt[v] instead of `till`
                       return false;
                    }
                }
                
                if(!visited[ngr]){
                    visited[ngr] = true;
                    cnt[ngr] = cnt[v] + 1;  // Fix: Use cnt[v] instead of `till`
                    q.push({ngr , {v , cnt[ngr]}});
                }
            }
        }
        
        return true;  // Fix: Return true when BFS completes successfully
    }

    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<bool> visited(n,false);
        
        for(int i=0; i<n; i++){
            if(!visited[i]){
                bool ans = bfs(i , visited , graph);
                if(!ans) return false;
            }
        }
    
        return true;
    }
};
