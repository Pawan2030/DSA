class Solution {
public:

    bool isPalindrome(int i, int j, string& s, int n){

        while(i < j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    string longestPalindrome(string s) {
        
        int len = 0;
        int idx = 0;
        int n = s.size();

        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){

                if(isPalindrome(i,j,s,n)){
                    if(len < j-i+1){
                        len = j-i+1;
                        idx = i;
                    }
                }
            }
        }
        return s.substr(idx, len);
    }
};