class Solution {
public:
    int countPalindromicSubsequence(string s) {
        
        int n   = s.length();
        int res = 0;
        unordered_set<int> st;

        for(char ch : s){
            st.insert(ch);
        }

        for(auto ch : st){

            int leftMost_idx  = -1;
            int rightMost_idx = -1;

            for(int i = 0; i<n; i++){    
                if(ch == s[i]){
                   if(leftMost_idx == -1){
                     leftMost_idx = i; 
                    } 
                    rightMost_idx = i;
                }
            }

            unordered_set<int> uc;
            for(int k=leftMost_idx+1; k<=rightMost_idx-1; k++){
                uc.insert(s[k]);
            }

            res += uc.size();
        }
        return res;
    }
};