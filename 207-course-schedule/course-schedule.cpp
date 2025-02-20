class Solution {
public:
    
    bool isCycle(int u, vector<bool> inRec, vector<bool> &visited, unordered_map<int,vector<int>>& adj){
         
         visited[u] = true;
         inRec[u]   = true;

         for(int &v : adj[u]){

            if(visited[v] && inRec[v]) return true;
            
            if(!visited[v] && isCycle(v,inRec,visited,adj)){
               return true;
            }
         }

         return false;
    }

    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        
        unordered_map<int,vector<int>> adj;

        for(auto vec : prerequisites){

            int v = vec[0];
            int u = vec[1];
            //u--->>v
            adj[u].push_back(v);
        }

        vector<bool> visited(n , false);
        vector<bool> inRec(n , false);
    
        for(int i=0; i<n; i++){
            
            if(!visited[i] && isCycle(i,inRec,visited,adj)){
               return false ;// cycle present so never possible to finish all course
            }
        }
        return true;
    }
};