class Solution {
public:
    string makeFancyString(string s) {

      stack<char> st;
      int size = s.length();
      int cnt = 0;

       for(int i=0; i<size; i++){
          
          if(i > 0 && s[i] == s[i-1]){
             cnt += 1;

             if(cnt < 3){
                st.push(s[i]);
             }
          }
          else{
            cnt = 1;
            st.push(s[i]);
          }
       }

       string res = "";

       while(!st.empty()){
          char ch = st.top();
          st.pop();
          res += ch;
       }

       reverse(begin(res) , end(res));

       return res;  
    }
};