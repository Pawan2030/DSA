class Solution {
public:

    int findCenter(vector<vector<int>>& edges) {

        int n = edges.size();
        unordered_map<int , vector<int> > mp;

        for(auto edge : edges){

            int val1 = edge[0];
            int val2 = edge[1];

            mp[val1].push_back(val2);
            mp[val2].push_back(val1);
        }
        
        for(auto it : mp){
           
           int val = it.first;
           vector<int> arr = it.second;


           if(arr.size() == n) return val;
            
        }
        return -1;
    }
};