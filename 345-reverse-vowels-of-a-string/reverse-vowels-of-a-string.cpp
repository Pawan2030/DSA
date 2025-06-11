class Solution {
public:
    
    bool isVowel(char &ch){
       return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' ; 
    }

    string reverseVowels(string s) {
        
        int n = s.size();
        int i =0;
        int j = n-1;

        while(i < j){

            while(i < j && isVowel(s[i]) == false){
                i++;
            }

            while(i < j && isVowel(s[j]) == false){
                j--;
            }
            
            // cout<<"s[i]-> "<<s[i]<<endl;
            // cout<<"s[j]-> "<<s[j]<<endl;

           if(i < j) {
        swap(s[i], s[j]);
        i++;
        j--;
    }
        }

        return s;
    }
};