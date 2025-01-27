class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {

       //prapare the adj list
       unordered_map<int,vector<int>> adj;
       vector<int> indegree(numCourses,0);

       for(int i=0; i < prerequisites.size();i++){
           
           int u = prerequisites[i][0];
           int v = prerequisites[i][1];
           //u------->v
           adj[u].push_back(v);
           indegree[v]++;
       } 

       queue<int> q;

       for(int i=0; i<numCourses; i++){
           
           if(indegree[i] == 0){
            q.push(i);
         }
       }

       unordered_map<int,unordered_set<int>> mp;

       while(!q.empty()){
          
          int top = q.front();
          q.pop();

          for(auto &ngr : adj[top]){
              mp[ngr].insert(top);

              for(auto& preq : mp[top]){
                 mp[ngr].insert(preq);
              }

              indegree[ngr]--;

              if(indegree[ngr] == 0){
                  q.push(ngr);
              }
              
          }

       }

       int Q = queries.size();
       vector<bool> res(Q,false);

       for(int i=0; i<Q; i++){
          
          int src = queries[i][0];
          int dit = queries[i][1];
          
          bool isPresent = false;

          if(mp[dit].find(src) != mp[dit].end()){
             isPresent = true;
          }

          res[i] = isPresent;
       }
       
       return res;
    }
};