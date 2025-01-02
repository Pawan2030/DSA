class Solution {
public:
   
   bool isVowels(char &ch){
     
     if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
      return true;

      return false;
   }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        
        int n = words.size();
        vector<int> sum(n , 0);

        for(int i=0; i<n; i++){
            
            int size = words[i].length();
            char ch1 = words[i][0];
            char ch2 = words[i][size-1];
                
              
                if(i == 0 && isVowels(ch1) && isVowels(ch2)){
                   sum[i] += 1;
                }
                else if(i > 0 && isVowels(ch1) && isVowels(ch2)){
                    sum[i] = sum[i-1]+1;
                }
                else if(i > 0){
                    sum[i] = sum[i-1];
                }
        }
        
        
        vector<int> res;

        for(auto &q : queries){

            int first  = q[0];
            int second = q[1];

            if(first == 0){
               int val = sum[second];
               res.push_back(val);
            }
            else{
                int val1 = sum[first-1];
                int val2 = sum[second];

                int final = val2 - val1;

                res.push_back(final);
            }
        }
        return res;
    }
};