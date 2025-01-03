class Solution {
public:
   
   void helper(string &s1 , unordered_map<string , int>& mp){
        
        int i =0;
        int j = 0;
        int size = s1.length();

        while(i < size){

            while(j < size && s1[j] != ' '){
                j++;
            }
            string temp = s1.substr(i , j-i);
            // for(int k=0; k<temp.length(); k++){
            //     cout<<temp[k];
            // }
            cout<<endl;
            mp[temp]++;

            j++;
            i = j;
        }
   }

    vector<string> uncommonFromSentences(string s1, string s2) {
        
        //token from string
        unordered_map<string , int> mp;

        helper(s1 , mp);
        helper(s2 , mp);

        vector<string> res;

        for(auto [st , num] : mp){
            cout<<num<<endl;
           if(num == 1){
              res.push_back(st);
           }
        }
        
        return res;
    }
};