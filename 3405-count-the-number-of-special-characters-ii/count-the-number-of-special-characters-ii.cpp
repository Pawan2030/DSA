class Solution {
public:
    int numberOfSpecialChars(string word) {
        
        int n = word.size();
        unordered_map<char , int> Lmp;
        unordered_map<char , int> Hmp;
        int ans = 0;

        for(int i=0; i<n; i++){
            if(word[i] >= 'A' && word[i] <= 'Z'){
                if(Hmp.find(word[i]) == Hmp.end())
                   Hmp[word[i]] = i;
            } 
            else{
                   Lmp[word[i]] = i;
            }
        }

        for(char ch = 'a' ; ch <= 'z' ; ch++){
             
             if(Lmp.find(ch) != Lmp.end() && Hmp.find(ch-'a' + 'A') != Hmp.end()){
                 int LowIdx  = Lmp[ch];
                 int HighIdx = Hmp[ch-'a' + 'A'];

                 if(LowIdx < HighIdx){
                    ans++;
                 }
             }
        }
        return ans;
    }
};