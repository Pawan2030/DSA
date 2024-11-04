class Solution {
public:
    string compressedString(string word) {
        
        int n = word.length();
        string comp = "";
        int i = 0;

        while(i < n){

            char ch = word[i];
            int cnt = 0;

            while(i < n && ch == word[i]){
                cnt += 1;
                i++;
            }

            while(cnt > 9){
                cnt -= 9;
                comp += "9";
                comp += ch;
            }

            comp += to_string(cnt);
            comp += ch;
        }

        return comp;
    }
};