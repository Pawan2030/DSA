class DSU{

    private:
      vector<int> parent;
      vector<int> rank;
      int comp;

    public:
      
      DSU(int n){
         
         parent.resize(n+1);
         rank.resize(n+1);
         comp  = n;

         for(int i=1; i<=n; i++){
            parent[i] = i;
         }
      }

      int find(int x){
        if(x == parent[x]) return x;

        return parent[x] = find(parent[x]);
      }

      void Union(int x , int y){
          
          int x_parent = find(x);
          int y_parent = find(y);

          if(x_parent == y_parent){
             return;
          }

          if(rank[x_parent] > rank[y_parent]){
            parent[y_parent] = x_parent;
          }
          else if(rank[x_parent] < rank[y_parent]){
             parent[x_parent] = y_parent;
          }
          else{
            parent[x_parent] = y_parent;
            rank[y_parent]++;
          }

          comp--;
      }

      bool once(){
         return comp == 1;
      }

};


class Solution {

public:  
     
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
         
         auto comp = [&](vector<int>& v1 , vector<int>& v2){
            return v1[0] > v2[0];
         };

         sort(begin(edges) , end(edges) , comp);

         DSU Alice(n);
         DSU Bob(n);

         int add = 0;

         for(auto &edge : edges){

            int type = edge[0];
            int u    = edge[1];
            int v    = edge[2];

            if(type == 3){

                bool isAdd = false;

                if(Alice.find(u) != Alice.find(v)){
                    Alice.Union(u , v);
                    isAdd = true;
                }

                if(Bob.find(u) != Bob.find(v)){
                    Bob.Union(u,v);
                    isAdd = true;
                }

                if(isAdd){
                    add++;
                }
            }
            else if(type == 2){
                 if(Bob.find(u) != Bob.find(v)){
                     Bob.Union(u,v);
                     add++;
                 }
            }
            else{
                if(Alice.find(u) != Alice.find(v)){
                    Alice.Union(u,v);
                    add++;
                }
            }
         }

         if(Alice.once() && Bob.once()){
            return edges.size() - add;
         }
         return -1;
    }
};