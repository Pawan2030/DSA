class Solution {
public:
    int n1,n2;
    int t[1001][1001];

    int solve(int i , int j , string &text1 , string &text2){

        if(i >= n1 || j >= n2) return 0;
        
        if(t[i][j] != -1) return t[i][j];
        if(text1[i] == text2[j]){
            return t[i][j] = 1+solve(i+1 , j+1 , text1 , text2);
        }
        else{
            return t[i][j] =  max(solve(i+1 , j , text1 , text2) , solve(i , j+1 , text1 , text2));
        }
    }

    int longestCommonSubsequence(string text1, string text2) {

       n1 = text1.length();
       n2 = text2.length();
       memset(t , -1 , sizeof(t));
       return solve(0 , 0 , text1 , text2); 
    }
};