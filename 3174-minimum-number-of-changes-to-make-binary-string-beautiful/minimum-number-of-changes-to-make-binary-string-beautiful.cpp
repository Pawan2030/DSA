class Solution {
public:
    int minChanges(string s) {
        
        int n = s.length();
        int cnt = 0;

        for(int i=0; i<n-1; i+=2){
            if(s[i] != s[i+1]){
                cnt += 1;
            }
        }
        return cnt;
    }
};