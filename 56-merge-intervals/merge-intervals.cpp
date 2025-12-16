class Solution {
public:

    vector<vector<int>> merge(vector<vector<int>>& in) {
        
        sort(in.begin() , in.end());
        int n = in.size();
        vector<vector<int>> res;

        int sp = in[0][0];
        int se = in[0][1];

        for(int i=1; i<n; i++){

            int es = in[i][0];
            int ee = in[i][1];

            if(se >= es){
                sp = min(sp , es);
                se = max(se , ee);
            }
            else{
                res.push_back({sp , se});
                sp = es;
                se = ee;
            }
        }
        
        res.push_back({sp , se});
        return res;
    }
};