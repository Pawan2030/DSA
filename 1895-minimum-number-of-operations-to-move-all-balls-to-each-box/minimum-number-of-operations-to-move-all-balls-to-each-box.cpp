class Solution {
public:
    vector<int> minOperations(string boxes) {
       
       int n = boxes.length();
       vector<int> res(n , 0);

       for(int i=0; i<n; i++){
         int total = 0;
         for(int j=0; j<n; j++){

            if(boxes[j] == '1'){
                total += abs(j-i);
            }
         }
         res[i] = total;
       } 
       return res;
    }
};