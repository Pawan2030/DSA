class Solution {
public:
    
    vector<vector<int>> res;
    int n;

    void solve(int idx, vector<int>& can, vector<int> &temp, int target){
        
        if(target == 0){
            res.push_back(temp);
            return;
        }
        if(target < 0 || idx >= n) return;
        for(int i=idx; i<n; i++){

            if(i > idx && can[i] == can[i-1]) continue;
            temp.push_back(can[i]);
            solve(i+1,can,temp,target-can[i]);
            temp.pop_back();
        }

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sort(begin(candidates),end(candidates));
        n = candidates.size();
        vector<int> temp;
        solve(0,candidates,temp,target);
        return res;
    }
};