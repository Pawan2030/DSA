class Solution {
public:

    int len1;
    int len2;

   bool solve(int k , string &str1 , string &str2){
        
        if(len1%k != 0 || len2%k != 0) return false;

        string temp = str1.substr(0 , k);
        int n1 = len1/k;
        int n2 = len2/k;

        string s1 = makeString(temp , n1);
        string s2 = makeString(temp , n2);

        return s1==str1 && s2==str2;
   }

   string makeString(string &temp , int n){

       string st = "";

       for(int i=0; i<n; i++){
           st += temp;
       }
       return st;
   }

    
    string gcdOfStrings(string str1, string str2) {
        
       len1 = str1.size();
       len2 = str2.size(); 

       for(int i=min(len1 , len2); i>=1 ; i--){

            if(solve(i , str1 , str2)){
                return str1.substr(0,i);
            }
       }
       return "";
    }
};