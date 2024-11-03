class Solution {
public:
    bool rotateString(string s, string goal) {
        
        int n1 = s.length();
        int n2 = goal.length();

        if(n1 != n2) return false;
        else if(s == goal) return true;
        
        int cnt = n1;
        int i = 1;

        while(cnt--){

            string temp = s.substr(i , n1-i) + s.substr(0 , i);

            if(temp == goal) return true;

            i++;
        }

        return false;
    }
};