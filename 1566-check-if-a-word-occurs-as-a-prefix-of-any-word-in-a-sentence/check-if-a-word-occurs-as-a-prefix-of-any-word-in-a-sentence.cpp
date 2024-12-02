class Solution {
public:

    int isPrefixOfWord(string sent, string word) {
        
        int n = sent.length();
        int size = word.length();
        int idx = INT_MAX;
        int space_Idx = 1;

        int i =0; int j = 0; int k =0;

        while(j < n){

            while(j < n && sent[j] != word[k]){
                if(sent[j] == ' '){
                    space_Idx++;
                }

                j++;
            }
            
            i = j;

            while(j < n && k < size && sent[j] == word[k]){
                j++;
                k++;
            }

            if(((i > 0 && sent[i-1] == ' ') || i == 0) && j-i == size){
                idx = min(idx , space_Idx);
            }
            
            k = 0;
        }

        return idx == INT_MAX ? -1 : idx;
    }
};