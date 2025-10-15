class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n = s.size();
        if(n == 0) return 0;
        
        vector<int> freq(256, 0);
        int maxi = 0;
    
        int i = 0;
        int j = 0;


        while(i < n && j < n){

            freq[s[j]] += 1;
             
            while(i < j && freq[s[j]] > 1){
                    freq[s[i]]--;
                    i++;
            }
            maxi = max(maxi , j-i+1);
            j++;
        }

        return maxi;
    }
};