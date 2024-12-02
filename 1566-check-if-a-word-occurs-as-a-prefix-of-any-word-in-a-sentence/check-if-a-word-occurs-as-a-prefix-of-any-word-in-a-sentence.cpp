class Solution {
public:
    int isPrefixOfWord(string s, string sw) {
        
        istringstream stream(s);
        string word;
        int idx = 1;

       while(stream >> word){
         
         if(word.find(sw) == 0){
            return idx;
         }

         idx++;
       }
        return -1;
    }
};