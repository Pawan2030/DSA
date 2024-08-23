class Solution {
public:

//    int gcd(int a , int b){
      
//       int div = 0;

//       for(int i = 1; i<=min(a , b); i++){
          
//           if(a%i == 0 && b%i == 0){
//               div = i;
//           }
//       }

//       return div;
//    }

    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return abs(a);
    }

    string fractionAddition(string exp) {

        int up = 0;
        int dn = 1;
        int i = 0;
        int size = exp.length();


       
        while(i < size){

           bool isNeg = false;
           int upper = 0 , neeche = 0;


            if(exp[i] == '-' || exp[i] == '+'){
                if(exp[i] == '-') isNeg = true;
                i++;
            }

            while(i < size && isdigit(exp[i])){

                int val = exp[i] - '0'; 
                upper = (upper*10) + val;
                i++;
            }

            if(exp[i] == '/'){
                i++;
            }

            while(i < size && isdigit(exp[i])){

                int val = exp[i] - '0'; 
                neeche = (neeche*10) + val;
                i++;
            }

            if(isNeg){
                upper *= -1;
            }

            up = (up*neeche) + (dn*upper);
            dn = (dn * neeche);
  
        }

        int div = gcd(up , dn);

        // if(div == 0){
        //     string res = to_string(up) + "/" + to_string(dn);
        //     return res;
        // }

        up /= div;
        dn /= div;

        string ans = to_string(up) + "/" + to_string(dn);
        return ans;
    }
};