class Solution {
public:

    int minimumDeletions(string s) {

        int n = s.length();
        stack<char> st;
        int cnt = 0;

        for(char ch : s){

            if(st.empty() || (st.top() == 'a' && ch == 'a')){
                st.push(ch);
            }
            else if(st.top() == 'b' && ch == 'a'){
                st.pop();
                cnt++;
            }
            else{
                st.push(ch);
            }

        }
        return cnt;
    }
};