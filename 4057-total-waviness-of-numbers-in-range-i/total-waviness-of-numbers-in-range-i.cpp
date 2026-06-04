class Solution {
public:
    
    void check(string &st , int &count){
        
        int n = st.size();

        for(int i=1; i<n-1; i++){
            if(((st[i-1]-'0') > (st[i] - '0' )) && ((st[i] - '0') < (st[i+1]-'0')) || ((st[i-1]-'0') < (st[i] - '0' )) && ((st[i] - '0') > (st[i+1]-'0'))){
                count++;
            }
        }
    }

    int totalWaviness(int num1, int num2) {
        
        if(num1 < 100){
           num1 = 100;
        }

        if(num2 < num1){
            return 0;
        }

        int count = 0;

        cout<<num1<<endl;
        cout<<num2<<endl;

        for(int num = num1; num <= num2; num++){
             
             string st = to_string(num);
             check(st , count);
        }

        return count;
    }
};