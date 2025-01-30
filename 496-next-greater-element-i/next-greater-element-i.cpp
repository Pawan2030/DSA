class Solution {
public:

    vector<int> nextGreaterElement(vector<int>& num1, vector<int>& num2) {
         
        int n = num2.size();
        unordered_map<int,int> mp;
        stack<int> st;

        for(int i=0; i<n; i++){

            while(!st.empty() && st.top() < num2[i]){
                mp[st.top()] = num2[i];
                st.pop();
            }
            st.push(num2[i]);
        }

        vector<int> res(num1.size());

        for(int i=0; i<num1.size(); i++){
            
            if(mp[num1[i]]){
                res[i] = mp[num1[i]];
            }
            else{
                res[i] = -1;
            }
        }
         
        return res;
    }
};