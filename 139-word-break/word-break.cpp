class Solution {
public:
   
   bool solve(int idx, string &s, int n,  unordered_map<string,int>& dist,  vector<int>& dp){
        
       if(idx == n){
          return dp[idx] = 1;
       }

       if(dp[idx] != -1){
          return dp[idx];
       }

       for(int len=1; len<=n; len++){
           
           string st = s.substr(idx, len);

           if(dist.find(st) != dist.end()){
              bool e = solve(idx+len, s, n, dist, dp);
              if(e) return dp[idx] = 1;
           }
       }
       return dp[idx] = 0;
   }


    bool wordBreak(string s, vector<string>& wordDict) {
        
        //map to store all dict words
        unordered_map<string,int> dist;
        int n = s.size();
        vector<int> dp(n+1, -1);

        for(string &word : wordDict){
            dist[word]++;
        }

        return solve(0, s, n, dist, dp);
    }
};