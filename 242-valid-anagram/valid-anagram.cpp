class Solution {
public:
    bool isAnagram(string s, string t) {
        
        vector<int> freq(26,0);

        if(s.size() != t.size()) return false;

        for(char &ch : s){
            freq[ch-'a']++;
        }

        for(char &ch : t){

            if(freq[ch-'a'] > 0){
                freq[ch-'a']--;
            }
            else{
                return false;
            }
        }

        return true;
    }
};