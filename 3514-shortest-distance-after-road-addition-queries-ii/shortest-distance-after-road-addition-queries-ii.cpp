class Solution {
public:
    
    void uDeletev(int u , int v , set<int>& st){
       
       auto low = st.lower_bound(u+1);
       auto lo  = st.lower_bound(v);

       st.erase(low , lo);
        
    }
   
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        
        set<int> st;

        for(int i=0; i<n; i++){ //o(n)
            st.insert(i);
        }

        vector<int> ans;

        for(int i=0; i<queries.size(); i++){ //o(n)
            
            int u = queries[i][0];
            int v = queries[i][1];

            uDeletev(u , v , st);//o(v-u-1)

            ans.push_back(st.size()-1);
        }

        return ans;
    }
};