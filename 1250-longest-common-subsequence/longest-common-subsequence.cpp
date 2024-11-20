class Solution {
public:
    
    //int cnt = 0;
    int n1; 
    int n2;
    int t[1001][1001];

    int solve(string &t1 , string &t2 , int i , int j){

        if(i >= n1 || j >= n2){
            return 0;
        }

        if(t[i][j] != -1){
            return t[i][j]; 
        }

        if(t1[i] == t2[j]){
           return t[i][j] = 1+solve(t1 , t2 , i+1 , j+1);
        }
        else{
            int l = solve(t1 , t2 , i+1 , j);
            int r = solve(t1 , t2 , i , j+1);
            return t[i][j] = max(l , r);
        }
    }

    int longestCommonSubsequence(string text1, string text2) {
        
        n1 = text1.size();
        n2 = text2.size();
        memset(t , -1 , sizeof(t));

        return solve(text1 , text2 , 0 , 0);
    }
};