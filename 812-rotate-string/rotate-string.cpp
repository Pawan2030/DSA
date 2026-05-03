class Solution {
public:
    bool rotateString(string s, string goal) {
        
        if(s.size() != goal.size()) return false;

        string temp = s+s;
        int n = temp.size();
        int cnt = 0;
        int ss = goal.size();

        int i = 0;

        while(i < n){

            int j = 0;
            int k = i;

            while(k < n && j < ss && temp[k] == goal[j]){
               // cout<<temp[i];
                k++;
                j++;

            }
            if(j == ss) return true;
            i++;
        }

        return false;
    }
};