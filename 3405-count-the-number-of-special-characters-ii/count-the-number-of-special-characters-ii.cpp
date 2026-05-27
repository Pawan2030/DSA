class Solution {
public:
    int numberOfSpecialChars(string word) {
        
        
        int n = word.size();
        int ans = 0;
        vector<int> Capfreq(26 , -1);
        vector<int> Lowfreq(26 , -1);

        for(int i=0; i<n; i++){
            
            if(word[i] >= 'A' && word[i] <= 'Z'){
                if(Capfreq[word[i] - 'A'] == -1){
                   Capfreq[word[i] - 'A'] = i;
                }
            }
            else{
                Lowfreq[word[i] - 'a'] = i;
            }
        }

        for(int i=0; i<26; i++){
            
            if(Capfreq[i] != -1 && Lowfreq[i] != -1){

                int CapIdx = Capfreq[i];
                int LowIdx = Lowfreq[i];

                if(LowIdx < CapIdx){
                    ans++;
                }
            }
        }
        return ans;
    }
};