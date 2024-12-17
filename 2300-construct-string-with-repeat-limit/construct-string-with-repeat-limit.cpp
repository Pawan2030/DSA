class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        
        vector<int> cnt(26 , 0);

        for(char &ch : s){
            cnt[ch-'a']++;
        }

        priority_queue<char> pq;

        for(int i=0; i<26; i++){
            char ch = 'a' + i;
            if(cnt[i] > 0)
             pq.push(ch);
        }
        
        string res;

        while(!pq.empty()){
           
           char ch = pq.top();
           pq.pop();
           int freq = cnt[ch-'a'];

           int k = min(freq , repeatLimit);
           cnt[ch-'a'] -= k;

           res.append(k , ch);

           if(cnt[ch-'a'] > 0 && !pq.empty()){
               
               char chh = pq.top();
               pq.pop();

               res.append(1 , chh);
               cnt[chh-'a']--;

               if(cnt[chh-'a'] > 0){
                 pq.push(chh);
               }

               pq.push(ch);
           }
        }
        return res;
    }
};