class Solution {
public:

    int n;

    void solve(int idx, string& s, unordered_map<string, int>& mp , vector<string> &result , string &curr) {

        // base case

        if (idx >= n) {
            result.push_back(curr);
            return;
        }

        // process

        for (int j = idx; j < n; j++) {
 
            string real = s.substr(idx, j - idx + 1);
            string temp = curr;

            if (mp.find(real) != mp.end()) {

                //string temp = curr;
                if(!curr.empty()){
                    curr += " ";
                }

                curr += real;

                solve(j + 1, s, mp , result , curr);
                
                curr = temp;
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {

        n = s.size();
        vector<string> result;
        string curr = "";

        // string real = "";

        unordered_map<string, int> mp;

        for (string& st : wordDict) {

            mp[st]++;
        }

        solve(0, s, mp , result , curr);

        return result;
    }
};