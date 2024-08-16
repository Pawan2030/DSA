class Solution {
public:

    int maxDistance(vector<vector<int>>& arrays) {
         
         int n = arrays.size();

         int res = INT_MIN;

         int mini = arrays[0].front();
         int maxi = arrays[0].back();

         for(auto it = 1; it<n; it++){
             
             int f = arrays[it].front();
             int l = arrays[it].back();

             int d1 = abs(mini - l);
             res = max(res , d1);
             d1  = abs(maxi - f);
             res = max(res , d1);

             maxi = max(maxi , l);
             mini = min(mini , f);

         }
         return res;
    }
};