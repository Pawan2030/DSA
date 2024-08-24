class Solution {
public:

   long func(long firstHalf , bool isEven){
        
       long num = firstHalf;

       if(isEven == false){
           firstHalf /= 10;
       }

       while(firstHalf > 0){
          
           long digit = firstHalf%10;
            firstHalf /= 10;

            num = num*10 + digit;
       }

       return num;
   }

    string nearestPalindromic(string n) {
         
       int length = n.length();
       long real = stol(n);

       int size = length%2 == 0 ? length/2 : (length/2)+1;

       long firstHalf =  stol(n.substr(0 , size));

       vector<long> vec;

       vec.push_back(func(firstHalf , length%2 == 0));
       vec.push_back(func(firstHalf+1 , length%2 == 0));
       vec.push_back(func(firstHalf-1 , length%2 == 0));
       vec.push_back(pow(10 , length) + 1);
       vec.push_back(pow(10 , length-1) - 1);

       long diff = LONG_MAX;
       long res = LONG_MAX;

       for(int i = 0; i<vec.size(); i++){
        
           if(vec[i] == real){
              continue;   
           } 
           else if(abs(vec[i] - real) < diff){
              res = vec[i];
              diff = abs(vec[i] - real);
           }
           else if(abs(vec[i] - real) == diff){
             res = min((int)res , (int)vec[i]);
           }
       }

       return to_string(res);

    }
};