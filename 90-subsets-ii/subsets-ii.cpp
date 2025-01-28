class Solution {
public:
    
    vector<vector<int>> res;
    int n;
    set<vector<int>> st;

    void solve(int i, vector<int>& nums, vector<int>& temp){
         
         if(i >= n){
            st.insert(temp);
            return;
         }

         temp.push_back(nums[i]);
         solve(i+1, nums,temp);
         temp.pop_back();
         solve(i+1,nums,temp);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       
       n = nums.size();
       vector<int> temp;
       sort(begin(nums) , end(nums));
       solve(0,nums,temp); 

       for(auto &it : st){
          res.push_back(it);
       }

       return res;
    }
};