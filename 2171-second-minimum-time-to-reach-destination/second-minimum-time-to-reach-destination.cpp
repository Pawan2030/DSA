class Solution {
public:

    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        
        vector<int> d1(n+1 , INT_MAX);
        vector<int> d2(n+1 , INT_MAX);
        d1[1] = 0;

        unordered_map<int , vector<int>> adj;

        for(auto &edge : edges){

            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        queue<pair<int , int>> q;
        q.push({0,1});
        int level = 0;

        while(!q.empty()){

            int size = q.size();

            while(size--){

                int it = q.front().second;
                int w  = q.front().first;
                q.pop();

                int div = w/change;

                if(div%2 == 1){
                    w = (div+1)*change;
                }

                for(auto ngr : adj[it]){

                    if(time + w < d1[ngr]){
                        d1[ngr] = time+w;
                        q.push({time+w , ngr});
                    }
                    else if(time + w > d1[ngr] && time + w < d2[ngr]){
                        d2[ngr] = time + w;
                        q.push({time+w , ngr});
                    }
                }
            }

            level++;
        }

        return d2[n];
    }
};