class Solution {
public:

    bool nonDigit(char &ch){
        return (ch == '0' || ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9' );
        //return (ch >= '0' && ch <= '9');
    }

    string clearDigits(string s) {

        int n = s.length();
        stack<char> st;

        for(char ch : s){

            if(!st.empty() && nonDigit(ch)){
                 st.pop();
            }

            if(!nonDigit(ch)){
                st.push(ch);
            }
        }

        string res = "";
        
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        
        reverse(begin(res) , end(res));
        return res;
    }
};