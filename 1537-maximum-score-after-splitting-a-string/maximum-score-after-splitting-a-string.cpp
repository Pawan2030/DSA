class Solution {
public:
    int maxScore(string s) {

       int zero = 0;
       int one  = 0;

       for(char ch : s){
          if(ch == '1') one++;
       } 

       int res = INT_MIN;

       for(int i=0; i<s.length()-1; i++){
           
           if(s[i] == '0'){
              zero++;
           }
           else{
              one--;
           }

           res = max(res , zero+one);
       }

       return res;
    }
};