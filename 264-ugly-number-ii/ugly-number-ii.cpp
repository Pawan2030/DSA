class Solution {
public:

    int nthUglyNumber(int n) {

        vector<int> arr(n+1,0);
        arr[1] = 1;

        int t1=1, t2=1 , t3 = 1;

        for(int i=2; i<=n; i++){

            int s1 = arr[t1]*2;
            int s2 = arr[t2]*3;
            int s3 = arr[t3]*5;

            int mini = min({s1 , s2 , s3});

            arr[i] = mini;

            if(mini == s1){
                t1++;
            }
            if(mini == s2){
                t2++;
            }
            if(mini == s3){
                t3++;
            }

        }

        return arr[n];
    }
};