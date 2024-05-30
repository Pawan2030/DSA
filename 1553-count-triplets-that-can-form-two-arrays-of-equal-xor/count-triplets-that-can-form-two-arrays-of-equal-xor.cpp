class Solution {
public:
    int countTriplets(vector<int>& arr) {

        int n = arr.size();
        int cnt = 0;
        int val1 = 0;

        for(int i=0; i<n-1; i++){

            val1 = arr[i];

            for(int j=i+1; j<n; j++){
                 
                 if(j != i+1){
                    val1 ^= arr[j-1];
                 }

                 int val2 = arr[j];

                for(int k=j; k<n; k++){

                    if(j != k){
                        
                        val2 ^= arr[k];
                    }

                    // cout<<"VAL1->"<<val1<<endl;
                    // cout<<"VAL2->"<<val2<<endl;

                    if(val1 == val2){
                        cnt++;
                    }
                }
            }
        }

        return cnt;
        
    }
};