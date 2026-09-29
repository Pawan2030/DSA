class Solution {
public:
    
    bool isCycle(int i, vector<bool>& visited, vector<bool>& inRec,  unordered_map<int , vector<int>>& mp){

        visited[i] = true;
        inRec[i]   = true;

        for(int &v : mp[i]){

            if(inRec[v] == true) return true;
            else if(!visited[v] && isCycle(v , visited , inRec , mp)){
                return true;
            }
        }

        inRec[i] = false;
        return false;

    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        

        unordered_map<int , vector<int>> mp;

        for(vector<int> &vec : prerequisites){

            int u = vec[0];
            int v = vec[1];

            mp[v].push_back(u);
        }

        vector<bool> visited(numCourses , false);
        vector<bool> inRec(numCourses , false);

        for(int i=0; i<numCourses; i++){

            if(!visited[i] && isCycle(i , visited , inRec , mp)){
                return false;
            }
        }
        return true;
    }
};