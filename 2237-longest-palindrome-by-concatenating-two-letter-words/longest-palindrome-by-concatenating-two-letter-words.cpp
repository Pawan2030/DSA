class Solution {
public:

    int longestPalindrome(vector<string>& words) {
        
        int res  = 0;
        unordered_map<string,int> mp;

        for(string word : words){

            string rw = word;
            swap(rw[0] , rw[1]);

            if(mp[rw] <= 0){
                mp[word]++;
            }
            else{
                res += 4;
                mp[rw]--;
                }
        }

        for(auto it : mp){

            string word = it.first;
            int count   = it.second;

            if(word[0] == word[1] && count > 0){
                res += 2;
                break;
            }
        }

        return res;
    }
};