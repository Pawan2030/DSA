class Solution {
public:

   /*

   int mask = same size of num bit size

    int size = 

    int mask = (1<<size) - 1;

    return num ^ mask;

   */

    int findComplement(int num) {

        // num = 5;
        //xor with 1 with ever char

        int num_bits = (int)(log2(num)) + 1;

        for(int i=0; i<num_bits; i++){
             
            num = num^(1<<i);
        }
        
        return num;
    }
};