class Solution {
public:

    bool isCycle(int u , vector<int> &visited , vector<int> &inRec ,  unordered_map<int,vector<int>> &adj){

        visited[u] = true;
        inRec[u] = true;

        for(int v : adj[u]){

            if(inRec[v] == true) return true;
            else if(!visited[v] && isCycle(v,visited,inRec,adj)){
                return true;
            }
        }

        inRec[u] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        unordered_map<int,vector<int>> adj;

        for(auto p : prerequisites){

            int u = p[1];
            int v = p[0];

            adj[u].push_back(v);
        }

        vector<int> visited(numCourses , false);
        vector<int> inRec(numCourses , false);

        for(int i=0; i<numCourses; i++){

            if(!visited[i] && isCycle(i , visited , inRec , adj)){
                return false; // not possible to complete the all cou
            }
        }

        return true;
    }
};