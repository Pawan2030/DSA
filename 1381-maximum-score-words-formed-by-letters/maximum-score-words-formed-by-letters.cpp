class Solution {
public:
    // Function to check if a word is valid with the given frequencies
    bool valid(string& word, unordered_map<char, int>& freq) {
        unordered_map<char, int> tempFreq = freq; // Use a temporary map to avoid modifying the original
        for (char& ch : word) {
            if (tempFreq[ch] <= 0) {
                return false;
            }
            tempFreq[ch]--;
        }
        // Update the original frequency map only if the word is valid
        freq = tempFreq;
        return true;
    }

    int backtracking(int idx, vector<string>& words, unordered_map<string, int>& calc, unordered_map<char, int>& freq) {
        // Base case: if we've considered all words, return 0
        if (idx >= words.size()) {
            return 0;
        }

        // Case 1: Skip the current word
        int skip = backtracking(idx + 1, words, calc, freq);

        // Case 2: Take the current word (if valid)
        int take = 0;
        if (valid(words[idx], freq)) {
            take = calc[words[idx]] + backtracking(idx + 1, words, calc, freq);
            // After the recursive call, restore the original frequencies by "un-using" the letters of the word
            for (char& ch : words[idx]) {
                freq[ch]++;
            }
        }

        // Return the maximum score between taking and skipping the current word
        return max(take, skip);
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        // Initialize the answer
        int ans = 0;

        // Count the frequency of each letter in the given set of letters
        unordered_map<char, int> freq;
        for (char& letter : letters) {
            freq[letter]++;
        }

        // Calculate the score for each word
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

        // Start the backtracking process
        ans = backtracking(0, words, calc, freq);

        return ans;
    }
};
