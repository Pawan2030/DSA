class Solution {
public:
    
    bool checkCycleCount(int u, int p, int val, vector<int>& cnt, vector<bool> &visited, vector<vector<int>>& graph) {
        visited[u] = true;
        cnt[u] = val;  // Store level of node

        for (int v : graph[u]) {
            if (v == p) continue; // Skip the parent node

            if (visited[v]) {
                // If we visit an already visited node, check for odd cycle
                if (((val+1) - cnt[v]) % 2 != 0) { 
                    return false; // Odd-length cycle found, not bipartite
                }
            } else {
                if (!checkCycleCount(v, u, val + 1, cnt, visited, graph)) {
                    return false;
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> cnt(n, -1);
        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                bool ans = checkCycleCount(i, -1, 0, cnt, visited, graph);
                if (!ans) return false;
            }
        }
        
        return true;
    }
};
