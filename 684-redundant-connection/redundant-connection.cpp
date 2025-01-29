class Solution {
public:

   bool dfs( unordered_map<int,vector<int>>& mp , int u, int v, vector<bool>& visited){
       
       visited[u] = true;

       if(u == v) return true;

       for(int ngr : mp[u]){

           if(visited[ngr] == true) continue;
           
           if(dfs(mp,ngr,v,visited)){
             return true;
           }
       }
       
       return false;
   }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        unordered_map<int,vector<int>> mp;
        int n = edges.size();

        for(int i=0; i<n; i++){

            int u = edges[i][0];
            int v = edges[i][1];
            
            vector<bool> visited(n,false);
            if(mp.find(u) != mp.end() && mp.find(v) != mp.end() && dfs(mp , u , v, visited)){
                return edges[i];
            }

            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        return {};
    }
};