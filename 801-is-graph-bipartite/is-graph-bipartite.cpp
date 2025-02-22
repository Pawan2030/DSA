
class Solution {
public:

bool checkCycleCount(int u, int p , int val , vector<int>& cnt ,  vector<bool> &visited , vector<vector<int>>& graph){

        visited[u] = true;
        cnt[u] = val;

        for(int v : graph[u]){

            if(v == p) continue;

            if(visited[v]){

               int p1 =  cnt[v];
               int p2 =  val;

               int data = p2-p1+1;

               if(data%2 != 0){
                   return false;
               }

            }
            else{
               bool get = checkCycleCount(v , u , val+1, cnt, visited, graph);

               if(!get) return false;
            }
        }
        
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<int> cnt(n,-1);
        vector<bool> visited(n , false);
        int cycle = 0;


        for(int i=0; i<n; i++){

            if(!visited[i]){
                bool ans = checkCycleCount(i , -1 , 1 , cnt , visited , graph);
                if(!ans) return false;
            }
        }
        
        return true;
    }
};