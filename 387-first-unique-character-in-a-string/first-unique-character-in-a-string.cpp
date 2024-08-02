class Solution {
public:
    
    //#define p pair<int,int>

    int firstUniqChar(string s) {

        vector<vector<int>> vec(26 , vector<int>(26 , 0));

        for(int i=0; i<s.length(); i++){
           
           char ch = s[i];
           int idx = ch-'a';

            int freq = vec[idx][0];

            vec[idx][0]  = freq + 1;
            vec[idx][1] = i;
        }

        int minIdx = INT_MAX;

        for(int i=0; i<26; i++){

            int freq = vec[i][0];
            int idx  = vec[i][1];

            if(freq == 1){
                minIdx = min(minIdx , idx);
            }
        }

        return minIdx == INT_MAX ? -1 : minIdx;
        
    }
};