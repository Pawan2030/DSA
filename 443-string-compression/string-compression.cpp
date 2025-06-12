class Solution {
public:
    int compress(vector<char>& chars) {
        
        int n = chars.size();
        int i = 0;
        int idx = 0;

        while(i < n){

            char ch = chars[i];
            int cnt = 0;

            while(i < n && ch == chars[i]){
                cnt++;
                i++;
            }
            
           chars[idx++] = ch;
            
            if(cnt > 1){

                string num = to_string(cnt);

                for(char ch : num){
                    chars[idx++] = ch;
                }
            }

        }
        
        return idx;
    }
};