class Solution {
public:
    
    string num_to_Binary(int num){
         
         string st = "";

         while(num > 0){
            
            int mod = num%2;
            num /= 2;
            st += to_string(mod);
         }

         reverse(st.begin() , st.end());

         return st;
    }

    int binary_to_Integer(string &st){

        int i = st.length()-1;
        int p = 0;
        int num = 0;

        while(i >= 0){

            int val = st[i] == '0' ? 0 : 1;
             
            num += (val * pow(2 , p));
            p++;
            i--;
        }
        return num;
    }

    int findComplement(int num) {
        
        string st = num_to_Binary(num);

        for(int i=0; i<st.length(); i++){

            st[i] = st[i] == '0' ? '1' : '0';
        }

        int ans = binary_to_Integer(st);

        return ans;
    }
};