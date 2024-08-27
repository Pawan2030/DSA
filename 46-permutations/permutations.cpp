class Solution {
public:
    
    vector<vector<int>> res;
    int n;

    void solve(vector<int>& nums , vector<int>& temp , unordered_set<int>& st){
        
        //base case
        if(temp.size() == n){
            res.push_back(temp);
            return;
        }

        //logic
        for(int i=0; i<n; i++){

            if(st.find(nums[i]) == st.end()){
                temp.push_back(nums[i]);
                st.insert(nums[i]);
                solve(nums , temp , st);
                temp.pop_back();
                st.erase(nums[i]);
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
     
     n = nums.size();
     vector<int> temp;
     unordered_set<int> st;
     solve(nums , temp , st);
     return res;  
    }
};