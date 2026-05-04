class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        vector<int> freq(256,0);
        int n = s.size();
        int ans = 0;

        int i=0;
        int j=0;

        while(j < n){
            
            while(freq[s[j]] > 0){
                freq[s[i]]--;
                i++;
            }

            freq[s[j]]++;
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};