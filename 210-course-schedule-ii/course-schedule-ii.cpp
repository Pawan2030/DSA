class Solution {
public:

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        unordered_map<int,vector<int>> adj;
        vector<int> in(numCourses , 0);

        for(auto it : prerequisites){
            int u = it[1];
            int v = it[0];

            adj[u].push_back(v);
            in[v]++;
        }

        queue<int> q;
        vector<int> ans;

        for(int i=0; i<numCourses; i++){
            
            if(in[i] == 0){
                q.push(i);
                ans.push_back(i);
            }
        }

        while(!q.empty()){

            int u = q.front();
            q.pop();

            for(int v : adj[u]){

                in[v]--;

                if(in[v] == 0){
                    q.push(v);
                    ans.push_back(v);
                }
            }
        }

        if(ans.size() == numCourses) return ans;

        return {};
    }
};