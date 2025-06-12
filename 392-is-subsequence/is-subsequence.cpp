class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int l1 = s.size(); //s
        int l2 = t.size(); //t

        int i = 0; //s
        int j = 0; //t

        while(i < l1 && j < l2){

            if(s[i] == t[j]){
                i++;
            }

            j++;
        }

        if(i == l1 || l1 == 0) return true;
        return false;
    }
};