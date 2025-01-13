class Solution {
public:

    int minimumLength(string s) {
        
        vector<int> vec(26,0);

        for(char ch : s){
            vec[ch-'a']++;
        }

        for(char ch : s){
            if(vec[ch-'a'] >= 3){
                vec[ch-'a'] -= 2;
            }
        }

        int length = 0;

        for(int i : vec){
            length += i;
        }

        return length;
    }
};