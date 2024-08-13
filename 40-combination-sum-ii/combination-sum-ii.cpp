class Solution {
public: 
    
    int n;
    vector<vector<int>> ans;
    vector<vector<int>> res;
    

    void solve(int i , vector<int>& can , int tar , vector<int>& temp , int& sum){
        
         if(sum == tar){
            ans.push_back(temp);
            return;
        }

        if(i >= n || sum > tar){
            return;
        }

        if(sum <= tar){
            temp.push_back(can[i]);
            sum += can[i];
            solve(i+1 , can , tar , temp , sum);
            sum -= can[i];
            temp.pop_back();
        }

        while(i+1 < n && can[i] == can[i+1]) i++;

        solve(i+1 , can , tar , temp , sum);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        n = candidates.size();
        vector<int> temp;
        int sum = 0;

        sort(begin(candidates) , end(candidates));

        solve(0 , candidates , target, temp , sum);

        sort(begin(ans) , end(ans));
        
        int i =0;

        while(i < ans.size()){

            auto it = ans[i];

            while(i < ans.size() && it == ans[i]){
                i++;
            }

            res.push_back(it);
        }
        return res;
    }
};