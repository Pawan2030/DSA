class Solution {
public:
    bool hasAlternatingBits(int n) {
        
         string s = "";

         while(n > 1){
              
              s += to_string(n%2);
              n /= 2;
         }

         //last one
          s+= '1';
          reverse(s.begin() , s.end());

          for(int i=1; i<s.size() ; i++){
               
               if(s[i-1] == s[i]){
                return false;
               }
          }

          return true;
    }
};