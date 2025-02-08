class Solution {
public:
    
    int n;
    vector<vector<int>> res;

    void solve(vector<int>& temp , vector<int>& nums, unordered_set<int>& st){

        if(temp.size() == n){
            res.push_back(temp);
            return;
        }
        
        for(int i=0; i<n; i++){
            if(st.find(nums[i]) == st.end()){
                temp.push_back(nums[i]);
                st.insert(nums[i]);
                solve(temp , nums, st);
                temp.pop_back();
                st.erase(nums[i]);
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        
       n = nums.size();
       vector<int> temp;
       unordered_set<int> st;
       solve(temp , nums , st);
       return res;
    }
};