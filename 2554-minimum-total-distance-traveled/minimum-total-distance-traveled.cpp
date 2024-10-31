class Solution {
public:
    long long maxi = 1e16;  // Represents an infinitely large distance when configuration is invalid.
private:
    long long solve(int r, int f, vector<int>& robot, vector<int>& v, vector<vector<long long>>& dp) {
        if (r == robot.size()) {
            return 0;  // All robots have been assigned to factories.
        }
        if (f == v.size()) {
            return maxi;  // No more factories to assign robots to; return a large number to represent infeasibility.
        }
        if (dp[r][f] != -1) {
            return dp[r][f];  // Use cached result to avoid recalculating.
        }

        // Choose to assign the current robot to the current factory or skip this factory.
        long long incl = abs(robot[r]-v[f]) + solve(r + 1, f + 1, robot, v, dp);
        long long excl = solve(r, f + 1, robot, v, dp);  // Skip the current factory for this robot.

        return dp[r][f] = min(incl, excl);
    }
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        // Sort robots and factories by position.
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        vector<int> v;
        for (auto i : factory) {
            int pos = i[0], lim = i[1];
            for (int j = 0; j < lim; j++) {
                v.push_back(pos);  // Expand each factory based on its limit.
            }
        }

        vector<vector<long long>> dp(robot.size() + 1, vector<long long>(v.size() + 1, -1));

        return solve(0, 0, robot, v, dp);
    }
};