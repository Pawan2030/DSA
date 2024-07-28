class Solution {
public:

    int nonSpecialCount(int l, int r) {

        int t = sqrt(r);
        vector<bool> prime(t+1 , true);

        prime[0] = prime[1] = false;

        for(int i=2; i<=t; i++){

            if(prime[i]){

                for(int j = i*i; j<=t; j+=i){
                    prime[j] = false;
                }
            }
        }

        int ans = 0;

        //special number

        for(int i=0; i<=t; i++){
            if(prime[i] && i*i >= l && i*i <= r) ans++;
        }

        int not_special = r-l+1 - ans;

        return not_special;
    }
};