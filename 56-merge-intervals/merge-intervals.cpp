class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& in) {
        
        int n = in.size();
        sort(begin(in) , end(in));
        vector<vector<int>> res;

        int mini = in[0][0];
        int maxi = in[0][1];

        for(int i=1; i<n; i++){

            int minEle = in[i][0];
            int maxEle = in[i][1];

            if(maxi >= minEle){
                mini =  min(mini , minEle);
                maxi = max(maxi , maxEle);
            }
            else{
                res.push_back({mini , maxi});
                mini = minEle;
                maxi = maxEle;
            }
        }

        res.push_back({mini , maxi});
        return res;
    }
};