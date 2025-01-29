class Solution {
public:
    
    vector<vector<int>> res;
    int n;

    void solve(int i, vector<int>& num, int tar, vector<int> &temp){
        
        if(tar == 0){
            res.push_back(temp);
            return;
        }

        if(i >= n){
           return;
        }

        if(tar >= num[i]){
            temp.push_back(num[i]);
            solve(i,num,tar-num[i],temp);
            temp.pop_back();
        }

        solve(i+1,num,tar,temp);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n = candidates.size();
        vector<int> temp;
        solve(0,candidates,target,temp);
        return res;
    }
};