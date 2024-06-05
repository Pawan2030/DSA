class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        
        vector<int> arr(26 , 0);
        int n = words.size();

        for(char ch : words[0]){
            arr[ch-'a']++;
        }

        int i = 1;

        while(i < n){

            vector<int> temp(26 , 0);
            string st = words[i++];

            for(char ch : st){
                temp[ch-'a']++;
            }

            for(int i=0; i<26; i++){
                arr[i] = min(arr[i] , temp[i]);
            }
        }

        for(int i=0; i<26; i++){
            cout<<arr[i]<<"  ";
        }

        vector<string> ans;

        for(int i=0; i<26; i++){
             
             int cnt = arr[i];

             while(cnt > 0){
                // cout<<"Hello"<<" ";
                char ch = i + 'a';
                // cout<<ch<<"  ";
                ans.push_back(string(1,ch));
                cnt -= 1;
             }
        }

        return ans;
    }
};