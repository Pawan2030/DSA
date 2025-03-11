class Solution {
public:
    int numberOfSubstrings(string s) {

        int n = s.length();
        vector<int> res(3 , 0);
        int i = 0;
        int j = 0;
        int ans = 0;

        while(j < n){

            char ch = s[j];
            int num = ch-'a';

            res[num]++;

            while(res[0] > 0 && res[1] > 0 && res[2] > 0){

                ans = ans + (n - j);
                
                ch = s[i];
                num = ch-'a';
                res[num]--;
                i++;
            }
            
            j++;
        }

        return ans;
    }
};