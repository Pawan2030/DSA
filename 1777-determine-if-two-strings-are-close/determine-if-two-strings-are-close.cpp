class Solution {
public:

    bool closeStrings(string word1, string word2) {
        
        int n1 = word1.size();
        int n2 = word2.size();

        if(n1 != n2) return false;

        vector<int> mp1(26);
        vector<int> mp2(26);

        for(char ch : word1){
            mp1[ch-'a']++;
        }

        for(char ch : word2){
            mp2[ch-'a']++;
        }

        for(int i=0; i<26; i++){

            if(mp1[i] == 0 && mp2[i] == 0) continue;
            else if(mp1[i] != 0 && mp2[i] != 0) continue;
            else return false;
        }

        sort(begin(mp1) , end(mp1));
        sort(begin(mp2) , end(mp2));
        
        return mp1 == mp2;
    }
};