class Solution {
public:
    string robotWithString(string s) {

        int n = s.size();

        string pre = "";
        string res = "";
        char ch = s[n-1];

        for(int i=n-1; i>=0; i--){
            ch   = min(ch , s[i]);
            cout<<ch;
            pre += ch;
        }

        reverse(begin(pre) , end(pre));
        string rest = "";
        
        for(int i=0; i<n; i++){
            rest += s[i];
            
         while (!rest.empty() && rest.back() <= pre[i + 1]) {
                res += rest.back();
                rest.pop_back();
            }
        }

        int l = rest.size();

        for(int i = l-1; i>=0; i--){
            res += rest[i];
        }
        
        return res;
    }
};