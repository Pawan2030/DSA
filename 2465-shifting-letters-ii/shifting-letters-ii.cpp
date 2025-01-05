class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        
        //different array technique
        int n = s.length();
        vector<int> sum(n , 0);

        for(auto &vec : shifts){
            int s = vec[0];
            int e = vec[1];
            int d = vec[2];

            int add;
            if(d == 0){
                add = -1;
            }
            else{
                add = 1;
            }

            sum[s] += add;

            if(e+1 < n){
                sum[e+1] -= add;
            }
        }

        for(int i=1; i<n; i++){
            sum[i] += sum[i-1];
        }
        
        string res = "";

        for(int i=0; i<n; i++){
            
            char ch = s[i];
            int val = ch-'a';
            int dis = sum[i];
            val += dis;
            val = val%26;

            if(val < 0){
                val += 26;
            }

            char wd = val + 'a';

            res += wd;
        }
        return res;
    }
};