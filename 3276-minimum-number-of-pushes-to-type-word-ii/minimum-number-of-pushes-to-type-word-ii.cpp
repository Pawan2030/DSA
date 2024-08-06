class Solution {
public:


    int minimumPushes(string word) {
         
         unordered_map<char , int> freq; //o(n)

         for(auto ch : word){ //0(n)
            freq[ch]++;
         }

         vector<int> vec;//o(n)

         for(auto it : freq){ //o(n)

            int f = it.second;
            vec.push_back(f);
         }

         auto comp = [&](int a , int b){
            cout<<a<<" "<<b<<endl;
            return a > b;
         };

         sort(begin(vec) , end(vec) , comp); //o(nlogn)

         //int mul = 1;
         int miniTyped = 0;

         for(int i=0; i<vec.size(); i++){ //o(n)
              
             int mul = i/8 + 1;

             miniTyped += (vec[i] * mul); 
         }

         return miniTyped;
    }
};