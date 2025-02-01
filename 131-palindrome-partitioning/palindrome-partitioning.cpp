class Solution {
public:
    
    vector<vector<string>> res;
    int n;

    bool isPalindrome(string &check){

        int i = 0;
        int j = check.length()-1;

        while(i < j){
            if(check[i] != check[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    void solve(int i, vector<string> &temp, string& s){

       if( i >= n){
          res.push_back(temp);
          return;
       }

       for(int l=1; l+i<=n; l++){

        string check = s.substr(i , l);
        if(isPalindrome(check)){
            temp.push_back(check);
            solve(i+l,temp,s);
            temp.pop_back();
        }

       }

    }

    vector<vector<string>> partition(string s) {
        vector<string> temp;
        n = s.size();
        solve(0, temp , s);
        return res;   
    }
};