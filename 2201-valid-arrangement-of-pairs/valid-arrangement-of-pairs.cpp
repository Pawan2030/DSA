class Solution {
public:

    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        
        unordered_map<int , vector<int>> adj;
        unordered_map<int,int> in , out ; //node in/out

        for(auto &it : pairs){
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            in[v]++;
            out[u]++;
        }

        //find strating node out[i] - in[i] = 1;
        
        int start = pairs[0][0];
        for(auto &it : adj){
            int node = it.first;

            if(out[node] - in[node] == 1){
                start = node;
                break;
            }
        }

        //dfs to produce right order for eluer path
        stack<int> st;
        st.push(start);
        vector<int> temp;

        while(!st.empty()){
           
           int top = st.top();
           if(!adj[top].empty()){
             int ngr = adj[top].back();
             adj[top].pop_back();
             st.push(ngr);
           }
           else{
              temp.push_back(top);
              st.pop();
           }
        }

        reverse(begin(temp) , end(temp));

        vector<vector<int>> res;

        for(int i=0; i<temp.size()-1; i++){
           res.push_back({temp[i] , temp[i+1]});
        }

        return res;
    }
};