class Solution {
public:

   void removeString(string &s , string str , int point , int &res){

       int i = 0; //place the char
       int j = 0; //read the char

       while(j < s.length()){

          s[i] = s[j];
          i++;
           
          if(i >= 2 && s[i-2] == str[0] && s[i-1] == str[1]){
              
              res += point;
              cout<<"I ->"<<i<<endl;
              i   -= 2;
          }
           j++;
       }
        s.resize(i);
   }

    int maximumGain(string s, int x, int y) {
        
        string max_point_str = x > y ? "ab" : "ba";
        string min_point_str = x > y ? "ba" : "ab";

        int max_point = max(x , y);
        int min_point = min(x , y);
        int res = 0;

        removeString(s , max_point_str , max_point , res);
        removeString(s , min_point_str , min_point , res);

        return res;
    }
};