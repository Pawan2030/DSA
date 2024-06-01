class Solution {
public:
    int scoreOfString(string s) {

       int cnt = 0;

       for(int i=1; i<s.size(); i++){
           
           int val1 = s[i-1] - 'a' ;
           int val2 = s[i] - 'a';

           cnt += abs(val1 - val2);
       }  
       return cnt;
    }
};