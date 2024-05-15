class Solution {
public:
    int row;
    int col;

    vector<vector<int>> Directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int DFS(vector<vector<int>>& grid, int i, int j) {

        // dfs return codition
        if (i < 0 || i >= row || j < 0 || j >= col || grid[i][j] == 0) {
            return 0;
        }

        int value = grid[i][j];
        grid[i][j] = 0;

        int sum = value;

        for (auto& dirc : Directions) {

            int new_i = i + dirc[0];
            int new_j = j + dirc[1];

            //cout << "SUM->" << sum << endl;
            sum = max(sum, value + DFS(grid, new_i, new_j));
        }

        // undo
        grid[i][j] = value;
        //cout << "FinalSUM->" << sum << endl;

        return sum;
    }

    int getMaximumGold(vector<vector<int>>& grid) {

        row = grid.size();
        col = grid[0].size();
        int result = 0;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {

                if (grid[i][j] != 0) {
                    result = max(result, DFS(grid, i, j));
                }
            }
        }
        return result;
    }
};