class Solution {
public:

   long root_result = 0;
   vector<int> count;
   int N;

    int dfs_Root(unordered_map<int,vector<int>> &mp, int curr , int prev , int depth){

        int total = 1;

        root_result += depth;

        for(int &child : mp[curr]){

            if(child == prev) continue;

            total  += dfs_Root(mp , child , curr , depth+1);
        }

         count[curr] = total;
         return total;
    }

    void dfs(unordered_map<int,vector<int>> &mp, int curr , int prev , vector<int> &result){

        for(int &child : mp[curr]){

            if(child == prev) continue;

            result[child] = result[curr] - count[child] + (N - count[child]);

            dfs(mp , child , curr , result);
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        
        unordered_map<int,vector<int>> mp;
        N = n;
        count.resize(n , 0);

        for(auto &edge : edges){

            int u = edge[0];
            int v = edge[1];

            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        
        root_result = 0;

        dfs_Root(mp , 0 , -1 , 0);

        vector<int> result(n , 0);

        result[0] = root_result;

        dfs(mp , 0 , -1 , result);

        return result;
        
    }
};