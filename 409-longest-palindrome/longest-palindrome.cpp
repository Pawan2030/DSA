class Solution {
public:

    int longestPalindrome(string s) {
         
          unordered_map<char , int> vec;
          int cnt = 0;

          for(char &ch : s){
             vec[ch]++;
          }

          for(auto it : vec){
              
              int num = it.second;
              cnt    += (2*(num/2));
          }

          int n = s.size();

          if(n > cnt){
             return cnt+1;
          }

          return cnt;
    }
};