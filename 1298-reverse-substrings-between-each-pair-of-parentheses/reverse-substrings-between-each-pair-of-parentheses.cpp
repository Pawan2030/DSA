class Solution {
public:

    string reverseParentheses(string s) {

        string res = "";
        stack<int> st;
        int n = s.length();
        int i = 0;

        while(i < n){

            if(s[i] == '('){
                st.push(res.length());
            }
            else if(s[i] == ')'){
                int start = st.top();
                st.pop();

                reverse(res.begin()+start , res.end());
            }
            else{
                res += s[i];
            }
            i++;
        }
        return res;
    }
};