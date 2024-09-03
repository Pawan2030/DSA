class Solution {
public:
    
    int func(int num){

        int sum = 0;

        while(num > 0){

            int digit = num%10;
            num       /= 10;
            sum += digit;
        }

        return sum;
    }

    int getLucky(string s, int k) {
        
        int res = 0;

        for(char &ch : s){

            int num = (ch-'a')+1;
            cout<<num;
            int val = func(num);
            res += val;
        }

        cout<<res<<endl;

        while(k > 1){
            int val = func(res);
            k--;
            res = val;
        }

        return res;
    }
};