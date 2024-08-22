class Solution {
public:

    int maxScoreSightseeingPair(vector<int>& values) {
        
        int n = values.size();
        vector<int> left(n  , -10000);
        vector<int> right(n , -10000);

        for(int i=1; i<n; i++){
            left[i] = max(values[i-1]-1 , left[i-1]-1);
        }

        for(int i = n-2; i>=0; i--){
            right[i] = max(values[i+1]-1 , right[i+1]-1);
        }

        int ans = INT_MIN;

        for(int i=0; i<n; i++){
            ans = max(ans , values[i] + max(left[i] , right[i]));
        }

        return ans;
    }
};