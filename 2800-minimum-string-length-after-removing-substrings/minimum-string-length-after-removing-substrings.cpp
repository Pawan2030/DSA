class Solution {
public:

    int minLength(string s) {
        
        stack<char> st;

        for(int i=0; i<s.size(); i++){

            char ch = s[i];

            if(ch == 'B' && !st.empty() && st.top() == 'A'){
                st.pop();   
            }
            else if(ch == 'D' && !st.empty() && st.top() == 'C'){
                st.pop();    
            }
            else{
                st.push(ch);
            }
        }

        return st.size();
    }
};