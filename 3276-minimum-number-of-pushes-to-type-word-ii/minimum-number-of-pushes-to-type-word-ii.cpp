class Solution {
public:


    int minimumPushes(string word) {
         
         unordered_map<char , int> freq;

         for(auto ch : word){
            freq[ch]++;
         }

         vector<int> vec;

         for(auto it : freq){

            int f = it.second;
            vec.push_back(f);
         }

         sort(rbegin(vec) , rend(vec));

         //int mul = 1;
         int miniTyped = 0;

         for(int i=0; i<vec.size(); i++){
              
             int mul = i/8 + 1;

             miniTyped += (vec[i] * mul); 
         }

         return miniTyped;
    }
};