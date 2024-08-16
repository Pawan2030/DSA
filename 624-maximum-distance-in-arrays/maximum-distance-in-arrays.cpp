class Solution {
public:

    int maxDistance(vector<vector<int>>& arrays) {
        
        sort(begin(arrays) , end(arrays));

        // int small = arrays[0][0];
       // int big   = INT_MIN;
        int diff = -1;

        for(auto it = 1; it<arrays.size(); it++){

            for(auto i=0; i<arrays[it].size(); i++){

                for(int k : arrays[0]){

                    int d = abs(k - arrays[it][i]);
                    diff  = max(diff , d);
                }
               
            }
        }

        return diff;
    }
};