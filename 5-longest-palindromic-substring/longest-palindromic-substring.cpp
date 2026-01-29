class Solution {
public:
    
    bool isPalindrome(string &ss, int i, int j){

       if(i >= j){
        return true;
       }

       if(ss[i] == ss[j]){
          return isPalindrome(ss, i+1, j-1);
       }
       else{
         return false;
       }
       
    }


    string longestPalindrome(string s) {
        
        int n = s.size();
        int maxLen = 0;
        int sIdx   = 0;

        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(isPalindrome(s , i , j)){
                     if((j-i+1) > maxLen){
                        maxLen = j-i+1;
                        sIdx = i;
                     }
                }
            }
        }
        return s.substr(sIdx , maxLen);
    }
};