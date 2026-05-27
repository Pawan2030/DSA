class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        unordered_map<int,vector<int>> adj;
        vector<int> indegree(numCourses , 0);

        for(auto it : prerequisites){

            int u = it[1];
            int v = it[0];  // u ---> v

            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;

        for(int i=0; i<numCourses; i++){

            if(indegree[i] == 0){
                q.push(i);
            }
        }

        int cnt = 0;
        
        while(!q.empty()){

            int u = q.front();
            q.pop();
            cnt++;

            for(auto v : adj[u]){

                indegree[v]--;

                if(indegree[v] == 0){
                    q.push(v);
                }
            }
        }

        return cnt == numCourses;
    }
};