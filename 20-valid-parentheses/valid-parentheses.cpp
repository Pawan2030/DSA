class Solution {
public:
    bool isValid(string s) {

        stack<char> st;
        int n = s.size();

        for(int i=0; i<n; i++){
            
            //char ch = s[i];

            if((s[i] == '(') ||( s[i] == '{' )|| (s[i] == '[')){
                st.push(s[i]);
            }
            else if(st.empty() && (s[i] == ')' || s[i] == '}' || s[i] == ']')){
                return false;
            }
            else if(s[i] ==')'){

                if(!st.empty() && st.top() != '(') return false;
                else st.pop();
                
            }
            else if(s[i] ==']'){

                if(!st.empty() && st.top() != '[') return false;
                else st.pop();
                
            }
            else if(!st.empty() && s[i] == '}'){
                if(st.top() != '{') return false;
                else st.pop();
            }
        }
        
        return st.size() == 0;
    }
};