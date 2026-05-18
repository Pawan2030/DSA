class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        
        int n = arr.size();
        set<int> st;
        if(n == 0) return false;

        queue<int> q;
        q.push(start); // put index into queue
        st.insert(start);

        while(!q.empty()){
             
             int idx = q.front();
             q.pop();

             if(arr[idx] == 0){
                return true;
             }

             if(st.find( idx + arr[idx]) == st.end() && idx + arr[idx] < n){
                q.push(idx + arr[idx]);
                 st.insert(idx + arr[idx]);
             }
             
             if(st.find( idx - arr[idx]) == st.end() && idx - arr[idx] >= 0){
                q.push(idx - arr[idx]);
                st.insert(idx - arr[idx]);
             }
        }

        return false;
    }
};