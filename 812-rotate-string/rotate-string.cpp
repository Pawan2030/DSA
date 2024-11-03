class Solution {
public:
    bool rotateString(string s, string goal) {
        
        int n1 = s.size();
        int n2 = goal.size(); 

        string temp = s + s;
       

        return(n1 == n2 && temp.find(goal) != string :: npos);

        
    }
};