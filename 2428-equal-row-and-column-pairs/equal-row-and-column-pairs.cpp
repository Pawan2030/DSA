class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        unordered_map<string , int> mp;

        for(int i=0; i<m; i++){

            string key = "";

            for(int j=0; j<n; j++){
                key += to_string(grid[i][j]) + ",";
            }

            mp[key]++;
        }

        //checking logic
        int count = 0;

        for(int j=0; j<n; j++){

            string key = "";

            for(int i=0; i<m; i++){
                key += to_string(grid[i][j]) + ",";
            }

            if(mp[key]){
                count += mp[key];
            }
        }

        return count;
    }
};