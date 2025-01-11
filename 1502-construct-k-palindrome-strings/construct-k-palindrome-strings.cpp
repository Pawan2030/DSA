class Solution {
public:
    bool canConstruct(string s, int k) {
        
        int n = s.length();
        
        if(n < k){
            return false;
        }

        if(n == k){
            return true;
        }

        vector<int> cnt(26,0);

        for(char ch : s){
            cnt[ch-'a']++;
        }

        int odd = 0;

        for(int i : cnt){
            if(i%2 != 0){
                odd++;
            }
        }

        if(odd <= k){
            return true;
        }
        
        return false;
    }
};