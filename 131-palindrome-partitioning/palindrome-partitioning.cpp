class Solution {
public:

    bool isPalindrome(string &temp){

        int i = 0;
        int j = temp.size()-1;

        while(i <= j){

            if(temp[i] != temp[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    
    void solve(int idx, string &s, int n, vector<string>& arr, vector<vector<string>> &res){
         
         if(idx == n){
            res.push_back(arr);
            return;
         }

         for(int l=1; l<=n-idx; l++){
             
             string temp = s.substr(idx , l);
             if(isPalindrome(temp)){
                arr.push_back(temp);
                solve(idx+l , s , n ,arr , res);
                arr.pop_back();
             }
         }

    }

    vector<vector<string>> partition(string s) {
        
        int n = s.size();
        vector<vector<string>> res;
        vector<string> arr;
        solve(0 , s , n , arr, res);
        return res;
    }
};