class Solution {
public:
    string reverseWords(string s) {
        
        vector<string> vec;
        int n = s.size();
        string res = "";
        int j = n-1;

        while(j >= 0){

            while(j >= 0 && s[j] == ' '){
                j--;
            }
            
            string temp = "";

            while(j>=0 && s[j] != ' '){
               temp += s[j];
               j--;
            }

            reverse(temp.begin() , temp.end());
            
            if(temp != "")
             vec.push_back(temp);
        }

        for(int i=0; i<vec.size(); i++){
            
            res += vec[i];
            if(i != vec.size()-1){
                res += ' ';
            }
        }

        return res;
    }
};