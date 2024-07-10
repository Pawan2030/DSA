class Solution {
public:

    int minOperations(vector<string>& logs) {

        int cnt = 0;
        int i   = 0;
        int n   = logs.size();

        while(i < n){

            if(logs[i] == "../"){

                if(cnt > 0)
                  cnt--;
            }
            else if(logs[i] == "./"){
                cnt = cnt;
            }
            else{
                cnt++;
            }
            i++;
        }
          
        if(cnt <= 0){
            return 0;
        }

         return cnt;
    }
};