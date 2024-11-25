class Solution {
public:
    
    void solve(int s , vector<vector<int>>& res , vector<int>& temp , int n , int k){
        
        if(temp.size() == k){
            res.push_back(temp);
            return;
        }

        if( s > n){
            return;
        }

        temp.push_back(s);
        solve(s+1 , res , temp , n , k);
        temp.pop_back();
        solve(s+1 , res , temp , n , k);

    }

    vector<vector<int>> combine(int n, int k) {
        
        vector<vector<int>> res;
        vector<int> temp;
        solve(1 , res , temp , n , k);
        return res;
    }
};