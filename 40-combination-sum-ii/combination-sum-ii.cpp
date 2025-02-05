class Solution {
public:
    
    int n;
    vector<vector<int>> res;

    void solve(int idx , vector<int>& can, int tar, vector<int>& temp){
        
        if(tar < 0){
            return;
        }

        if(tar == 0){
            res.push_back(temp);
            return;
        }

        for(int i=idx; i<n; i++){
            
            if(i > idx && can[i] == can[i-1]) continue;

            temp.push_back(can[i]);
            solve(i+1,can,tar-can[i],temp);
            temp.pop_back();
        }

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        n = candidates.size();
        sort(begin(candidates) , end(candidates));
        vector<int> temp;
        solve(0,candidates,target,temp);
        return res;
    }
};