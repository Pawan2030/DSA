class Solution {
public:
    bool checkRecord(string s) {

        int n = s.size();
        int absent = 0;
        int i  = 0;

        while (i < n) {

            if (s[i] == 'A') {
                absent++;

                if (absent >= 2) {
                    return false;
                }

                i++;

            } 
            else if (s[i] == 'L') {

                int cnt = 0;
                char curr = 'L';

                while (i < n && curr == s[i]) {

                    cnt++;

                    if (cnt >= 3) {
                        return false;
                    }

                    i++;
                }
            }
            else{
             
                i++;
            }  
        }

        return true;
    }
};