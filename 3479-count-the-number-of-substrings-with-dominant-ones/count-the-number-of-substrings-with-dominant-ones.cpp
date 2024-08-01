class Solution {
public:
    int numberOfSubstrings(string s) {

        int n = s.length();
        int dominantONE = 0;

        vector<int> prefix(n , 0);

        for(int i=0; i<n; i++){

            if(s[i] == '1'){
                prefix[i] = 1;
            }
        }

        for(int i=1; i<n; i++){
            prefix[i] += prefix[i-1];
            //cout<<prefix[i]<<" , ";
        }

        //let's start to doing real logic implementation

        for(int i=0; i<n; i++){

            int ones = 0;
            int zero = 0;

            for(int j=i; j<s.length(); j++){
                 
                ones = prefix[j];
                if(i != 0) ones -= prefix[i-1];
                zero = (j - i + 1 ) - ones;

                // pos-1 
                if((zero*zero) > ones){
                    j += ((zero*zero) - ones - 1);
                }

                //pos - 2

                if((zero*zero) <= ones){
                    
                    dominantONE++;

                    if((zero*zero) < ones){

                        int diff = sqrt(ones) - zero;
                        int nextj = j + diff;

                        if(nextj >= n){
                           dominantONE += (n-j-1);
                        }else{
                           dominantONE += diff;
                        }
                        j = nextj;
                    }
                }
            }
        }
        return dominantONE;
    }
};