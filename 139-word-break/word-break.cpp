class Solution {
public:
    
    int n;
    int t[301];

    bool solve(int idx, string &s, unordered_map<string,int> &mp){

        if(idx == n){
            return t[idx] = true; 
        }

        if(t[idx] != -1) return t[idx];

        if(mp.find(s.substr(idx , n - idx)) != mp.end()){
            return t[idx] = true;
        }

        for(int l=1; l<=n; l++){
            
            string temp = s.substr(idx , l);

            if(mp.find(temp) != mp.end() && solve(idx+l , s , mp)){
                return t[idx] = true;
            }
        }

        return t[idx] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        
        unordered_map<string,int> mp;
        n = s.size();
        memset(t , -1 , sizeof(t));
        for(string &word : wordDict){
            mp[word]++;
        }
        return solve(0 , s , mp);
    }
};