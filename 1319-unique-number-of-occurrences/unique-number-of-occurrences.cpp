class Solution {
public:

    bool uniqueOccurrences(vector<int>& arr) {
        
        unordered_map<int,int> mp;

        for(int num : arr){
            mp[num]++;
        }

        unordered_set<int> st;

        for(auto it : mp){

            int count = it.second;

            if(st.find(count) != st.end()){
                return false;
            }

            st.insert(count);
        }

        return true;
    }
};