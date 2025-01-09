class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        
        int n = pref.length();
        int res = 0;

        for(int i=0; i<words.size(); i++){

            string word = words[i].substr(0 , n);
            if(word == pref) res++;
        }
        return res;
    }
};