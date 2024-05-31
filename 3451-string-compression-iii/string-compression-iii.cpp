class Solution {
public:
    string compressedString(string word) {
        
        string comp = "";
        int n = word.size();
        int i =0;

        while(i < n){
             
             char ch = word[i];
             int cnt = 0;

             while(ch == word[i]){
                cnt++;
                i++;
             }

             while(cnt > 9){
                cnt  -= 9;
                comp += '9';
                comp += ch;
             }

             comp += to_string(cnt);
             comp += ch;
        }
        return comp;
    }
};