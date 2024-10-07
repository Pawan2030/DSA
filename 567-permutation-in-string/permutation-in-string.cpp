class Solution {
public:

    bool checkInclusion(string s1, string s2) {
        
        if(s1.length() > s2.length()) return false;
        
        sort(begin(s1) , end(s1));
        int n = s1.length();

        for(int i = 0; i<=s2.length()-n; i++){

            //make sub-string size = n

            string st = s2.substr(i , n);
            sort(begin(st) , end(st));

            if(s1 == st) return true;
        }

        return false;
    }
};