class Solution {
public:
   
   
   int t[301];

   bool solve(int idx, string &s, int n,  unordered_map<string,int>& dist,  vector<bool>& dp){
        
       if(idx == n){
          return t[idx] = true;
       }

       if(t[idx] != -1){
          return t[idx];
       }

       for(int len=1; len<=n; len++){
           
           string st = s.substr(idx, len);

           if(dist.find(st) != dist.end()){
              bool e = solve(idx+len, s, n, dist, dp);
              if(e) return t[idx] = true;
           }
       }
       return t[idx] = false;
   }


    bool wordBreak(string s, vector<string>& wordDict) {
        
        //map to store all dict words
        unordered_map<string,int> dist;
        int n = s.size();
        vector<bool> dp(n+1, -1);
        memset(t , -1 , sizeof(t));

        for(string &word : wordDict){
            dist[word]++;
        }

        return solve(0, s, n, dist, dp);
    }
};