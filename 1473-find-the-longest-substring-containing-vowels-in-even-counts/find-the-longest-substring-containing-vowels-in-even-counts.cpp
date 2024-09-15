class Solution {
public:
    int findTheLongestSubstring(string s) {
        int mask = 0;
        unordered_map<int, int> first_occurrence;
        first_occurrence[0] = -1;  // base case for mask=0
        int maxLen = 0;
        
        for (int i = 0; i < s.length(); i++) {
            // Update the mask based on the current character
            if (s[i] == 'a') mask ^= 1;
            else if (s[i] == 'e') mask ^= 2;
            else if (s[i] == 'i') mask ^= 4;
            else if (s[i] == 'o') mask ^= 8;
            else if (s[i] == 'u') mask ^= 16;

            // Check if this mask was seen before
            if (first_occurrence.find(mask) != first_occurrence.end()) {
                maxLen = max(maxLen, i - first_occurrence[mask]);
            } else {
                first_occurrence[mask] = i;  // store first occurrence of this mask
            }
        }
        
        return maxLen;
    }
};