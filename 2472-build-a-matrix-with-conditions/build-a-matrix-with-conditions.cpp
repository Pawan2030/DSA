class Solution {
public:

    void buildGraph(vector<vector<int>>& arr , unordered_map<int , vector<int>>& mp){

        for(auto vec : arr){

            int u = vec[0];
            int v = vec[1];

            mp[u].push_back(v);
        }
    }

    // void topoSort(int u , unordered_map<int , vector<int>> adj , vector<bool>& visited , stack<int>& st , int& count){

    //     visited[u] = 1;
    //     count += 1;

    //     for(auto ngr : adj[u]){

    //         if(!visited[ngr]){
    //             topoSort(ngr , adj , visited , st , count);
    //         }
    //     }

    //     st.push(u);
    // }

     bool topoSort(unordered_map<int, vector<int>>& adj, vector<int>& order, int k) {
        unordered_map<int, int> inDegree;
        for (int i = 1; i <= k; ++i) inDegree[i] = 0;
        for (auto& p : adj) {
            for (auto& v : p.second) {
                inDegree[v]++;
            }
        }

        queue<int> q;
        for (int i = 1; i <= k; ++i) {
            if (inDegree[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            order.push_back(u);

            for (int v : adj[u]) {
                inDegree[v]--;
                if (inDegree[v] == 0) q.push(v);
            }
        }

        return order.size() == k;
    }


    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        
        unordered_map<int , vector<int>> row_adj;
        unordered_map<int , vector<int>> col_adj;
        vector<vector<int>> answer(k , vector<int>(k , 0));

        int count_row = 0;
        int count_col = 0;


        buildGraph(rowConditions , row_adj);
        buildGraph(colConditions , col_adj);
        
        vector<int> row_sort;
        vector<int> col_sort;


        if (!topoSort(row_adj, row_sort, k) || !topoSort(col_adj, col_sort, k)) {
            return {}; // Return empty matrix if there's a cycle
        }

        unordered_map<int , int> colPos; // num -> col postion

        for(int i = 0; i<col_sort.size(); i++){
            colPos[col_sort[i]] = i;
        }

        for(int i = 0; i<row_sort.size(); i++){

            int val = row_sort[i];

            int r = i;
            int c = colPos[val];

            answer[r][c] = val;
        }

        return answer;
    }
};