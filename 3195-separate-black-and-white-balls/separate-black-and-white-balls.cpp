class Solution {
public:

    long long minimumSteps(string s) {
        
        long long zero = 0;
        long long one  = 0;
        int i = 0;
        int n = s.length();

        while(i < n){

            if(s[i] == '0'){
                zero++;
            }
            else{
                one++;
            }
            i++;
        }

        i = 0;
        long long ans = 0;

        while(i < n){

            if(s[i] == '1'){
                ans += zero;
            }
            else{
                zero--;
            }
            i++;
        }
        return ans;
    }
};