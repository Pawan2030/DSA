class Solution {
public:

    int takeCharacters(string s, int k) {
        
        int window = 0; // sbko delete maar diya
        int i =0;
        int j =0;
        int n = s.length();
        
        int a=0, b=0, c=0;

        for(char &ch : s){

            if(ch =='a') a++;
            else if(ch == 'b') b++;
            else c++;
        }

        if(a < k || b < k || c < k) return -1;

        while(j < n){

            if(s[j] =='a') a--;
            else if(s[j] == 'b') b--;
            else c--;

            while(i <= j && (a < k || b < k || c < k)){
               if(s[i] =='a') a++;
               else if(s[i] == 'b') b++;
               else c++;
               i++;
            } 

            window = max(window , j-i+1) ;  
            j++;
        }

        return n - window;
    }
};