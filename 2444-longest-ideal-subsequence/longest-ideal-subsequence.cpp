class Solution {
public:
    int longestIdealString(string s, int k) {
        
        int n = s.length();

        vector<int> arr(26 , 0);

        int result = 0;

        for(int i=0; i<n; i++){

            char ch = s[i] - 'a';

            int left  = max(0 , ch-k);
            int right = min(25 , ch+k);
            
            int longest = 0;
            for(int j= left; j<=right; j++){
              longest = max(arr[j] , longest);
            }

            arr[ch] = max(arr[ch] , longest+1);
            result  = max(result , arr[ch]);
        }
         return result;
    }
};