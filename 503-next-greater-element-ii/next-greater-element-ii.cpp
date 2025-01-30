class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& num) {

        int n = num.size();
        vector<int> res(n,-1);
        stack<pair<int,int>> st;

        for(int i=0; i<2*n; i++){

            while(!st.empty() && st.top().first < num[i%n]){
                
                int idx  = st.top().second;
                res[idx] = num[i%n];

                st.pop();
            }
            st.push({num[i%n] , i%n});
        }

        return res;
    }
};