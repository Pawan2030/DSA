class Solution {
public:

    bool areAlmostEqual(string s1, string s2) {
        
        int n = s1.length();
        int diff = 0;

        vector<int> freq1(26,0);
        vector<int> freq2(26,0);

        for(int i=0; i<n; i++){
            freq1[s1[i]-'a']++;
            freq2[s2[i]-'a']++;
            if(s1[i] != s2[i]) diff++;
        }

        for(int i=0; i<26; i++){
            if(freq1[i] != freq2[i]) return false;
        }

        return diff<=2;
    }
};