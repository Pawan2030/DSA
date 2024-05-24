class Solution {
public:

   int n;

    void solve(int i , vector<string>& words , vector<vector<string>>& result , vector<string>& temp){

        if(i >= n){
            result.push_back(temp);
            return;
        }

        temp.push_back(words[i]);
        solve(i+1 , words , result , temp);

        temp.pop_back();
        solve(i+1 , words , result , temp);

    }

    int possible(vector<string> &it ,  unordered_map<char , int> count , vector<int>& score){
         
        int ans = 0;

        for(string &st : it){
             
             for(char &ch : st){
                 
                 if(count[ch] <= 0){
                    return 0;
                 }

                 ans += score[ch-'a'];
                 count[ch]--;
             }
        }
        return ans;
    }


    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {

        vector<vector<string>> result;
        vector<string> temp;
        n = words.size();

        solve( 0 , words , result , temp);

        //lets go
        unordered_map<char , int> count;

        for(char &ch : letters){
            count[ch]++;
        }

        int mini = INT_MIN;

        for(auto &it : result){
            
            int ans = possible(it , count , score);
            mini = max(mini , ans);
        }

        return mini;
    }
};