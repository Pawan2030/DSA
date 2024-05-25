class Solution {
public:
    
    int n;

    void solve(int idx , string &s , vector<string>& arr , unordered_map<string , int>& mp , string &temp){

        //base case
        if(idx >= n){
            arr.push_back(temp);
            return;
        }

        //GAME
        for(int j = idx ; j<n; j++){

            string curr = s.substr(idx , j - idx + 1);

            if(mp.find(curr) != mp.end()){
                
                string let = temp;

                if(!temp.empty()){
                    temp +=  " ";
                }
                
                temp += curr;
        
                solve(j+1 , s , arr , mp , temp);

                temp = let;
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {

        vector<string> arr;
        n = s.size();

        unordered_map<string , int> mp;
        string temp = "";

        for(string &st : wordDict){
            mp[st]++;
        }

        solve(0 , s , arr , mp , temp);

        return arr;       
    }
};