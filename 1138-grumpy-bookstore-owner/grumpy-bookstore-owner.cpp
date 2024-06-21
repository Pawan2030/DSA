class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        
         int n = customers.size();
         int maxWin = INT_MIN;
         int temp = 0;

         for(int i = 0; i<min(n , minutes); i++){
             
             if(grumpy[i] == 1){
                 temp += customers[i];
             }
         }
         
        maxWin = max(maxWin , temp);


         for(int i = minutes ; i < n ; i++){
            

            if(grumpy[i] == 1){
                 temp += customers[i];
            }

            if(grumpy[i - minutes] == 1){
                 temp -= customers[i - minutes];
            }

            maxWin = max(maxWin , temp);
         }

         int result = 0;

         for(int i=0; i<n; i++){

            if(grumpy[i] == 0){
                 result += customers[i];
            }
         }

         cout<<"MAX  ->  "<<maxWin<<endl;
         cout<<"RESULT ->  "<<result<<endl;

         return result + maxWin;
    }
};