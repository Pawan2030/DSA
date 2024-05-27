class Solution {
public:
    bool checkRecord(string s) {
        
        int n = s.size();

        int ab = 0;
        int cl = 0;
        int i = 0;

        while(i < n){

            char ch = s[i];

            if(ch == 'A'){
                ab++;
                cl = 0;
            }
            else if(ch == 'P'){
                cl = 0;
            }
             else {
                cl++;
            }

            if(ab >= 2 || cl >= 3){
                return false;
            }

            i++;
        }
        return true;
    }
};