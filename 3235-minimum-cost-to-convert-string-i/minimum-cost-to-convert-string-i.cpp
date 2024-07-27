class Solution {
public:
    void miniCostFinder(char s, unordered_map<char, vector<pair<char, int>>>& adj, vector<long long>& vec) {
        priority_queue<pair<long long, char>, vector<pair<long long, char>>, greater<pair<long long, char>>> pq;
        pq.push({0, s});
        vec[s - 'a'] = 0;

        while (!pq.empty()) {
            auto [w, u] = pq.top();
            pq.pop();

            for (auto& it : adj[u]) {
                char ch = it.first;
                int d = it.second;

                if (w + d < vec[ch - 'a']) {
                    vec[ch - 'a'] = w + d;
                    pq.push({w + d, ch});
                }
            }
        }
    }

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        unordered_map<char, vector<pair<char, int>>> adj;
        int n = cost.size();

        for (int i = 0; i < n; i++) {
            char u = original[i];
            char v = changed[i];
            int w = cost[i];
            adj[u].push_back({v, w});
        }

        vector<vector<long long>> vec(26, vector<long long>(26, LLONG_MAX));

        for (char c = 'a'; c <= 'z'; c++) {
            miniCostFinder(c, adj, vec[c - 'a']);
        }

        int size = source.size();
        long long miniCost = 0;

        for (int i = 0; i < size; i++) {
            if (source[i] != target[i]) {
                long long rate = vec[source[i] - 'a'][target[i] - 'a'];

                if (rate == LLONG_MAX) {
                    return -1;
                }

                miniCost += rate;
            }
        }

        return miniCost;
    }
};