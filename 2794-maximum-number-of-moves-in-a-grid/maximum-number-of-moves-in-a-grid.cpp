class Solution {
public:
    int m, n;
    vector<vector<int>> dp;

    int solve(int i, int j, int prev, vector<vector<int>>& grid) {
        if (i < 0 || i >= m || j >= n || prev >= grid[i][j]) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int ans = 0;
        ans = max(ans, 1 + solve(i - 1, j + 1, grid[i][j], grid)); // Up-Right
        ans = max(ans, 1 + solve(i, j + 1, grid[i][j], grid));      // Right
        ans = max(ans, 1 + solve(i + 1, j + 1, grid[i][j], grid));  // Down-Right

        return dp[i][j] = ans;
    }

    int maxMoves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        dp.assign(m, vector<int>(n, -1));

        int ans = 0;
        for (int i = 0; i < m; i++) {
            ans = max(ans, solve(i, 0, -1, grid));
        }

        return ans-1;
    }
};
