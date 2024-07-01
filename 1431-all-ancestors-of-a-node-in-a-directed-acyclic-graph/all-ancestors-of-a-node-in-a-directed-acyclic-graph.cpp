class Solution {
public:
    void solve(int i , unordered_map<int , vector<int>>& adj , vector<int>& temp ,  vector<bool>& vec){
         
          //if(vec[i] == 1) return;

          for(auto it : adj[i]){

            if(vec[it] == 1) continue;
            
               temp.push_back(it);
               vec[it] = 1;  
             
             solve(it , adj , temp , vec);
          }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        
        unordered_map<int , vector<int>> adj;

        for(auto& edge : edges){

            int u = edge[0];
            int v = edge[1];

            adj[v].push_back(u);
        }

        vector<vector<int>> res;

        for(int i = 0; i<n ; i++){

            vector<bool> vec(n , 0);
            vector<int> temp;
            solve(i , adj , temp , vec);
            sort(begin(temp) , end(temp));
            res.push_back(temp);

        }

        return res;
    }
};