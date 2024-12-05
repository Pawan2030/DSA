class Solution {
public:
    bool canChange(string s1, string s2) {
        stack<pair<char, int>> st1, st2;
        int i, n = s1.size();
        for(i=0; i<n; i++)
        {
            if(s1[i]=='L')
            {
                st1.push({'L', i});
            }
            else if(s1[i]=='R')
            {
                st1.push({'R', i});
            }
            if(s2[i]=='L')
            {
                st2.push({'L', i});
            }
            else if(s2[i]=='R')
            {
                st2.push({'R', i});
            }
        }
        
        // If number of L's and R's in st1 and st2 are not same 
        if(st1.size() != st2.size())
        {
            return false;
        }
        while(!st1.empty() and !st2.empty())
        {
            // If the sequence is not same, then it is always impossible
            if(st1.top().first != st2.top().first)
            {
                return false;
            }
            
            if(st1.top().first == 'R')
            {
                // If R in s1 is ahead of R in target string, then we can never move it towards the left
                // Therefore, it is always impossible
                if(st1.top().second > st2.top().second)
                {
                    return false;
                }
            }
            else
            {
                // If L in s1 is before of L in target string, then we can never move it towards the right
                // Therefore, it is always impossible
                if(st1.top().second < st2.top().second)
                {
                    return false;
                }
            }
            st1.pop();
            st2.pop();
        }
        return true;
    }
};