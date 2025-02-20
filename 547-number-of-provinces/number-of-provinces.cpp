class Solution {
public:

    void DFS(int u, vector<bool>& visited, unordered_map<int,vector<int>> &adj){

        visited[u] = true;

        for(int &v : adj[u]){

            if(!visited[v]){
                DFS(v , visited , adj);
            }
        }

    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        unordered_map<int,vector<int>> adj;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){

                if(i != j && isConnected[i][j] == 1){
                    adj[i+1].push_back(j+1);
                }
            }
        }

        vector<bool> visited(n+1,false);
        int res = 0;

        for(int i=1; i<=n; i++){

            if(!visited[i]){
                res++;
                DFS(i , visited , adj);
            }
        }
        
        return res;
    }
};