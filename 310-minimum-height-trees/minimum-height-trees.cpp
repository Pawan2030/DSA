class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

        unordered_map<int,vector<int>> mp;
        vector<int> indegree(n,0);

        if(n==1){
            return {0};
        }

        for(auto &edge : edges){

            int u = edge[0];
            int v = edge[1];

            indegree[u]++;
            indegree[v]++;

            mp[u].push_back(v);
            mp[v].push_back(u);
        }

        queue<int> q;

        for(int i=0; i<n; i++){

            if(indegree[i] == 1){
                q.push(i);
            }
        }

        while(n > 2){

            int size = q.size();

            n -= size;

            while(size--){

                int u = q.front();
                q.pop();

                for(auto &v : mp[u]){
                    indegree[v]--;

                    if(  indegree[v] == 1){
                        q.push(v);
                    }
                }

            }
        }

        vector<int> final;

        while(!q.empty()){

            final.push_back(q.front());
            q.pop();
        }

        return final;  
    }
};