class Solution {
public:
    
    void checkAndRemove(string &part ,  string &st){

        int j = part.length();
        int n = st.length();
        string temp = st.substr(n-j,j);

        if(temp == part){  
            while(j--){
                st.pop_back();
            }
        }
    }

    string removeOccurrences(string s, string part) {
        
        string st = "";
        int p = part.length();

        for(char &ch : s){
            
            st.push_back(ch);

            if(st.length() >= p){
                checkAndRemove(part , st);
            }
        }

        return st;
    }
};