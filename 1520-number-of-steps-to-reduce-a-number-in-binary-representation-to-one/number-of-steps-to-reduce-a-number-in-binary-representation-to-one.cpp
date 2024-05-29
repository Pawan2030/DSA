
class Solution {
public:
    int numSteps(string s) {
        
        s.insert(s.begin(), '0');
        cout << s << endl;

        int size = s.size();
        int cnt = 0;
        int i = size - 1;

        while (i > 1) { 
            if (s[i] == '0') { 
    
                i--;
            } else { 
        
                while (i >= 0 && s[i] == '1') {
                    s[i] = '0';
                    i--;
                    cnt++;
                }
                if (i >= 0) {
                    s[i] = '1';
                }
            }
            
            cnt++;
        }

        return cnt;
    }
};