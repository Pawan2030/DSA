class Solution {
public:

    int lengthOfLongestSubstring(string s){
        
        set<char> st;
        int n = s.size();

        int i=0;
        int j=i;
        int ans=0;

        while(j < n){

            while(st.find(s[j]) != st.end()){
                st.erase(s[i]);
                i++;
            } 

            st.insert(s[j]);
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};