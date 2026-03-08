class Solution {
public:
    bool isPalindrome(string s) {
        
        int n = s.size();
        string ss = "";

        for(int i=0; i<n; i++){

            char ch = s[i];

            if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch  >= '0' && ch <= '9')){
                ss += tolower(ch);
            }
        }

        // for(char ch : ss){
        //     cout<<ch;
        // }

        int i = 0;
        int j = ss.size()-1;

        while(i < j){

            if(ss[i] != ss[j]){
                return false;
            }
            i++;
            j--;
        }

        return true;
    }
};