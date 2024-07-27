class Solution {
public:
    void floydWarshall(vector<vector<int>>& mat) {
        int n = mat.size();

        // Apply Floyd-Warshall algorithm
        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (mat[i][via] != INT_MAX && mat[via][j] != INT_MAX) {
                        mat[i][j] = min(mat[i][j], mat[i][via] + mat[via][j]);
                    }
                }
            }
        }
    }

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<int>> mat(26, vector<int>(26, INT_MAX));

        // Initialize the matrix with 0 for self transformations
        for (int i = 0; i < 26; i++) {
            mat[i][i] = 0;
        }

        // Apply the given transformations
        int n = original.size();
        for (int i = 0; i < n; i++) {
            mat[original[i] - 'a'][changed[i] - 'a'] = min(mat[original[i] - 'a'][changed[i] - 'a'], cost[i]);
        }

        // Apply Floyd-Warshall to find all-pairs shortest paths
        floydWarshall(mat);

        long long totalCost = 0;

        // Calculate the total minimum cost for transforming source to target
        for (int i = 0; i < source.size(); i++) {
            if (source[i] != target[i]) {
                int cost = mat[source[i] - 'a'][target[i] - 'a'];
                if (cost == INT_MAX) return -1;  // Transformation is not possible
                totalCost += cost;
            }
        }

        return totalCost;
    }
};
