class Solution {
public:
    
    void checkAndRemove(string &part , stack<char> &st){

        int n = part.length();
        int j = n;
        string temp = "";

        while(j--){
           temp += st.top();
           st.pop();
        }
        reverse(begin(temp),end(temp));

        if(temp != part){  
            for(char &ch : temp){
                st.push(ch);
            }
        }
    }

    string removeOccurrences(string s, string part) {
        
        stack<char> st;
        int p = part.length();

        for(char &ch : s){
            
            st.push(ch);
            if(st.size() >= p){
                checkAndRemove(part , st);
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