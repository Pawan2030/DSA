class Solution {
public:

   string removeString(string s , string str , int point , int &res){

       stack<char> st;
       int i = 0;

       while(i < s.length()){
           
           if(!st.empty() && st.top() == str[0] && s[i] == str[1]){
               res += point;
               st.pop();
           }
           else{
             st.push(s[i]);
           }
           i++;
       }

       //return rest string 
       string temp = "";

       while(!st.empty()){
          temp += st.top();
          st.pop();
       }

       reverse(temp.begin() , temp.end());
       return temp;
   }


    int maximumGain(string s, int x, int y) {


       string max_point_str = x > y ? "ab" : "ba";
       string min_point_str = x > y ? "ba" : "ab";

       int max_point = max(x , y);
       int min_point = min(x , y);
       int res = 0;

       string temp = removeString(s   , max_point_str , max_point , res);
       string tem = removeString(temp , min_point_str , min_point , res);

       return res;
    }
};