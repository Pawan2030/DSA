class Solution {
public:
    string mostCommonWord(string s, vector<string>& banned) {
        unordered_map<string, int> mp;
        unordered_set<string> bannedSet(banned.begin(), banned.end());
        int n = s.size();
        int i = 0;

        while (i < n) {
            string temp = "";
            // Skip non-alphabet characters
            while (i < n && !isalpha(s[i])) i++;

            // Build the word
            while (i < n && isalpha(s[i])) {
                temp += tolower(s[i]);
                i++;
            }

            if (temp != "" && bannedSet.find(temp) == bannedSet.end()) {
                mp[temp]++;
            }
        }

        string res;
        int maxFreq = 0;
        for (auto& [word, freq] : mp) {
            if (freq > maxFreq) {
                res = word;
                maxFreq = freq;
            }
        }

        return res;
    }
};
