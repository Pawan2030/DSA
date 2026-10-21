class Solution {
public:
    
    void solve(int i, int n, int tar, vector<int>& cand, vector<int> temp, vector<vector<int>>& res){

        if(tar == 0){
            res.push_back(temp);
            return;
        }

        if(i>=n || cand[i] > tar){
            return;
        }

        if(cand[i] <= tar){
            temp.push_back(cand[i]);
            solve(i+1,n,tar-cand[i],cand,temp,res);
            temp.pop_back();
        }
        
        while(i+1<n && cand[i] == cand[i+1]){
            i++;
        }
        solve(i+1,n,tar,cand,temp,res);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        int n = candidates.size();
        sort(candidates.begin() , candidates.end());
        vector<int> temp;
        vector<vector<int>> res;
        solve(0,n,target,candidates,temp,res);
        return res;
    }
};