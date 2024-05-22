class Solution {
public:
   
   int n;

   bool isPalindrome(string &st , int s , int e){
      
      while(s <= e){
         
         if(st[s] != st[e]){
            return false;
         }
         s++;
         e--;
      }

      return true;
   } 

   void solve(int idx , string &s , vector<vector<string>>& result, vector<string>& temp){

    if(idx >= n){
       result.push_back(temp);
       return;
    }
    
    for(int i = idx ; i<n; i++){

      if(isPalindrome(s , idx , i)){
          temp.push_back(s.substr(idx , i - idx + 1));
          solve(i+1 , s , result , temp);
          temp.pop_back();
      }
    }
}
    
    vector<vector<string>> partition(string s) {
        
        n = s.size();

        vector<vector<string>> result;
        vector<string> temp;

        solve(0 , s , result , temp);

        return result;
    }
};