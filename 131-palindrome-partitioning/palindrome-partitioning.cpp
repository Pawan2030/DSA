class Solution {
public:

    bool isPalindrome(string &st , int s, int e){

         while(s < e){

            if(st[s] != st[e]){
                return false;
            }
            s++;
            e--;
         }

         return true;
    }
   
    void solve(int idx , string &s , int n , vector<vector<string>> &result , vector<string> &temp){
         
          if(idx >= n){
            result.push_back(temp);
            return;
          }

          for(int i=idx ; i<n; i++){
              
              if(isPalindrome(s , idx , i)){
                 temp.push_back(s.substr(idx , i - idx + 1));
                 solve(i+1 , s , n , result , temp);
                 temp.pop_back();
              }
          }

          return;
    }
    
    vector<vector<string>> partition(string s) {

       int n = s.size();  
       vector<vector<string>> result;

       vector<string> temp;

       solve(0 , s , n , result , temp);

       return result;
    }
};