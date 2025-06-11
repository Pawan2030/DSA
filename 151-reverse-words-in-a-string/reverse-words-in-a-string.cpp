class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        int n = s.size();
        int j = n - 1;

        while(j >= 0) {
            // Skip trailing spaces
            while(j >= 0 && s[j] == ' ') j--;

            if(j < 0) break;

            string word = "";
            while(j >= 0 && s[j] != ' ') {
                word += s[j];
                j--;
            }

            reverse(word.begin(), word.end());
            words.push_back(word);
        }

        // Join with single space
        string result = "";
        for(int i = 0; i < words.size(); i++) {
            result += words[i];
            if(i != words.size() - 1)
                result += ' ';
        }

        return result;
    }
};
