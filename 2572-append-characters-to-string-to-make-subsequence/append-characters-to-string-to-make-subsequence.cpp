class Solution {
public:

    int appendCharacters(string s, string t) {
         
         int n = s.size();
         int m = t.size();
         int cnt = 0;

         int i=0, j=0;

         while(i < n && j < m){
              
              if(s[i] == t[j]){
                  i++;
                  j++;
              }
              else if(s[i] != t[j]){
                  i++;
              }
         }

         if(i == n && j < m){
             cnt += (m-j);
         }

         return cnt;
    }
};