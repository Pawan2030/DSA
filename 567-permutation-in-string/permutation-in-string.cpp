class Solution {
public:
    
    bool checked(vector<int>& s1count , vector<int>& s2count){
            //check
            bool present = false;
            for(int i=0; i<26; i++){
                if(s1count[i] != s2count[i]){
                    present = false;
                    break;
                }
                else{
                    present = true;
                }
            }

            return present == true;
    }

    bool checkInclusion(string s1, string s2) {

        int n1 = s1.length();
        int n2 = s2.length();

        if(n1 > n2) return false;

        vector<int> s1count(26 , 0);

        for(char ch : s1){
            s1count[ch-'a']++;
        }

        vector<int> s2count(26 , 0);
        int i = 0;
        int j = 0;

        while(j < n1){
           s2count[s2[j]-'a']++;
           j++;
        }

        bool check = checked(s1count , s2count);
        if(check) return true;

        while(j <  n2){
            
            s2count[s2[j]-'a']++;
            s2count[s2[i]-'a']--;
            bool present = checked(s1count , s2count);
            if(present) return true;
            i++;
            j++;
        }  
        return false; 
    }
};