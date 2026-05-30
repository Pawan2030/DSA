class Solution {
public:
    bool order(int u, vector<bool>& visited, unordered_map<int,vector<int>>& adj,  stack<int>& st,  vector<int> inRec){

        visited[u] = true;
        inRec[u]  = true;

        for(int v : adj[u]){
            
            if(inRec[v] == true) return true;
            else if(!visited[v] && order(v,visited,adj, st, inRec)){
               return true;
            }
        }

        st.push(u);
        inRec[u] = false;
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        unordered_map<int,vector<int>> adj;

        for(auto prep : prerequisites){

            int u = prep[1];
            int v = prep[0];

            adj[u].push_back(v);
        }

        vector<bool> visited(numCourses , false);
        vector<int> inRec(numCourses , false);
        stack<int> st;

        for(int i=0; i<numCourses; i++){
            if(!visited[i] && order(i,visited,adj, st, inRec)){
                return {};
            }
        }

        // if(st.size() != numCourses){
        //     return {};
        // }
        
        vector<int> ans;

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};