class Solution {
public:
    bool valid(string& word, unordered_map<char, int>& freq) {

        unordered_map<char, int> temp = freq;

        for (char& ch : word) {

            if (temp[ch] <= 0) {
                return false;
            }

            temp[ch]--;
        }
        
        freq = temp;
        return true;
    }

    int backtracking(int idx, vector<string>& words,
                     unordered_map<string, int>& calc,
                     unordered_map<char, int>& freq) {

        // base case
        if (idx >= words.size()) {
            return 0;
        }

        // take
        // whice one is taken --> check validity

        int take = 0;

        if (valid(words[idx], freq)) {

            take = calc[words[idx]] +
                                 backtracking(idx + 1, words, calc, freq);

             for (char& ch : words[idx]) {
                freq[ch]++;
            }
        }

        // not take
        int skip = backtracking(idx + 1, words, calc, freq);

        return max(take, skip);
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters,
                      vector<int>& score) {

        // count freq of all characters
        unordered_map<char, int> freq;

        for (char& letter : letters) {

            freq[letter]++;
        }

        // count all score in begining

        unordered_map<string, int> calc;

        for (string& word : words) {

            int total = 0;

            for (char& ch : word) {

                if (freq.find(ch) != freq.end()) {
                    total += score[ch - 'a'];
                } else {
                    total = 0;
                    break;
                }
            }

            calc[word] = total;
        }

        // let game begin's

        return backtracking(0, words, calc, freq);
    }
};