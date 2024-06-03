class Solution {
public:
    bool hasAlternatingBits(int n) {
        
         string s = "";

         while(n > 1){
              
              if(n%2 != 0){
                  s+= to_string(1);
              }
              else{
                  s+= to_string(0);
              }
              n /= 2;
         }

         //last one
          s+= to_string(1);
          reverse(s.begin() , s.end());

          for(int i=1; i<s.size() ; i++){
               
               if(s[i-1] == s[i]){
                return false;
               }
          }

          return true;
    }
};