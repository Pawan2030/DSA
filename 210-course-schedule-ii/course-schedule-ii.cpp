class Solution {
public:
    
    vector<int> topologicalSort(unordered_map<int ,vector<int>> &adj , int n , vector<int> &indegree){
        
        //bfs
        queue<int> q;
        vector<int> topo;
        int cnt = 0;

        for(int i=0; i<n; i++){
            if(indegree[i] == 0){
                cnt++;
                q.push(i);
                topo.push_back(i);
            }
        }

        while(!q.empty()){

            int u = q.front();
            q.pop();

            for(int &v : adj[u]){

                indegree[v]--;
                if(indegree[v] == 0){
                    cnt++;
                    q.push(v);
                    topo.push_back(v);
                }
            }
        }

        if(cnt == n){
            return topo;
        }

        return {};
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        unordered_map<int ,vector<int>> adj;
        vector<int> indegree(numCourses , 0);

        for(auto vec : prerequisites){
           
           int a = vec[0];
           int b = vec[1];

           //[a , b]
           //b -> a
           indegree[a]++;
           adj[b].push_back(a);
        }

        return topologicalSort(adj , numCourses , indegree);
    }
};