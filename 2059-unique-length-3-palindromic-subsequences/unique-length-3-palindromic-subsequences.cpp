class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        int result = 0;
        unordered_set<char> letters;

        for(int i=0;i<n;i++)
        {
            letters.insert(s[i]);
        }

        for(auto letter : letters)
        {
            int left_idx = -1;
            int right_idx = -1;

            for(int i=0;i<n;i++)
            {
                if(s[i]==letter)
                {
                    if(left_idx==-1)
                    {
                        left_idx = i;
                    }
                     right_idx = i;
                }
            }

            unordered_set<char> st;

            for(int middle_ele = left_idx+1 ; middle_ele <= right_idx-1; middle_ele++)
            {
                st.insert(s[middle_ele]);
            }

            result += st.size();
        }

        return result;
        
    }
};