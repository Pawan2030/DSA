class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        
        int n = pref.length();
        int res = 0;

        for(int i=0; i<words.size(); i++){

            string word = words[i];
            int cnt = 0;
            for(int j=0; j<n; j++){
                if(word[j] != pref[j]) break;
                cnt++;
            }
            if(cnt == n) res++;
        }
        return res;
    }
};