class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        int n = strs.size();
        unordered_map<string,vector<string>> mp;

        for(int i=0; i<n; i++){

            string key = strs[i];
            sort(key.begin() , key.end());
            mp[key].push_back(strs[i]);
        }

        vector<vector<string>> res;

        for(auto &arr : mp){
            res.push_back(arr.second);
        }

        return res;
    }
};