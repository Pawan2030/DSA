class Solution {
public:
    string mostCommonWord(string s, vector<string>& banned) {
        
        unordered_map<string , int> mp;
        unordered_set<string> Ban(banned.begin() , banned.end());
        int n = s.size();
        int j = 0;


        while(j < n){
            
            string temp = "";

            while (j < n && !isalpha(s[j])) j++;
            
            while(j < n && isalpha(s[j])){
                char ch = tolower(s[j]);
                temp += ch;
                j++;
            }
            
            if(temp != "" && Ban.find(temp) == Ban.end())
               mp[temp]++;
        }

        int cnt = 0;
        string res;

        for(auto it : mp){

            string ss = it.first;
            int count = it.second;

            if(cnt < count){
               res = ss;
               cnt = count;
            }
        }
        
        return res;
    }
};