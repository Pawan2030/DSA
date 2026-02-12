class Solution {
public:
    
    int t[1001][1001];

    int solve(int i, int j, string &s1, string &s2, int n){

        if(i >= n || j >= n){
            return 0;
        }

        if(t[i][j] != -1){
            return t[i][j]; 
        }

        if(s1[i] == s2[j]){
            return t[i][j] = 1+solve(i+1,j+1,s1,s2,n);
        }
        else{
            return t[i][j] = max(solve(i+1,j,s1,s2,n) , solve(i,j+1,s1,s2,n));
        }

    }

    int longestPalindromeSubseq(string s) {

        int n = s.size();
        string s1 = s;
        memset(t,-1,sizeof(t));
        reverse(s.begin() , s.end());
        return solve(0,0,s,s1,n); 
    }
};