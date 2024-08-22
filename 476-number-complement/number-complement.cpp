class Solution {
public:


    int findComplement(int num) {
    
    int size = (int)(log2(num))+1;

    int val = 0;

    int i = 0;

   while(num){
     
     if(!(num&1)){
         
         val |= (1<<i);
     }
     num >>= 1;
     i++;
   }

     return val;

    }
     

























        // num = 5;
        //xor with 1 with ever char

        // int num_bits = (int)(log2(num)) + 1;

        // for(int i=0; i<num_bits; i++){
             
        //     num = num^(1<<i);
        // }
        
        // return num;

        

    //int mask = same size of num bit size

    // int size = (int)(log2(num)) + 1;

    // unsigned int mask = (1U<<size) - 1;

    // return num ^ mask;


};