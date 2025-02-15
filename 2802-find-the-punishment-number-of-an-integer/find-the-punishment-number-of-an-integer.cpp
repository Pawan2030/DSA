class Solution {
public:

   bool check(int s , string st , int val , int sum){
       
       if(s == st.length()){
          return sum == val;
       }

       if(sum > val) return false;
       
       bool ans = false;

       for(int len = 1; s+len<=st.length(); len++){
            string sub = st.substr(s , len);
            int v = stoi(sub);
            ans = ans || check(s+len, st , val , sum+v);
            if(ans) return true;
       }

       return false;
   }

    int punishmentNumber(int n) {
        
        int res = 0;

        for(int i=1; i<=n; i++){

            int num = i*i;
            string st = to_string(num);

            if(check(0 ,st , i , 0)){
                res += num;
            }
        }

        return res;
    }
};