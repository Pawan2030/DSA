class Solution {
public:

    long long maxPoints(vector<vector<int>>& points) {
        
        int m = points.size();
        int n = points[0].size();

        vector<long long> prev(n);

        for(int col=0; col<n; col++){
            prev[col] = points[0][col];
        }

        for(int row = 1; row < m; row++){

            vector<long long> left(n , 0);
            vector<long long> right(n , 0);
          
            for(int col = 0; col < n; col++){

                left[col]        = col == 0 ? prev[col] : max(prev[col] , left[col-1]-1);
                right[n-col-1]   = col == 0 ? prev[n-col-1] : max(prev[n-col-1] , right[n-col]-1);
            }

            for(int j=0; j<n; j++){

                prev[j] = points[row][j] + max(left[j] , right[j]);
            }

        }

        return *max_element(begin(prev) , end(prev));
    }
};