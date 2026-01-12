class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
         unordered_map<int , vector<int>> mp;
         vector<int> in(numCourses , 0);

         for(auto prep : prerequisites){
              int u = prep[1];
              int v = prep[0];
              mp[u].push_back(v);
              in[v]++;
         }

        queue<int> q;
        vector<int> res; 

         for(int i=0; i<in.size(); i++){
             
             if(in[i] == 0){
                q.push(i);
             }
         }

         while(!q.empty()){

            int it = q.front();
            q.pop();
            res.push_back(it);

            for(int ngr : mp[it]){

                in[ngr]--;

                if(in[ngr] == 0){
                    q.push(ngr);
                }
            }
         }

         return res.size() == numCourses ? res : vector<int>{};
    }
};