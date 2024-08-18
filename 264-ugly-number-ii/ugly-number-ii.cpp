class Solution {
public:
     
    //  the moral story is to find out that ugle number are multiple of power of 2 , 3 , 5

    int nthUglyNumber(int n) {

        priority_queue<long long , vector<long long> , greater<long long>> pq;
        pq.push(1);
        unordered_set<long long> st;
        long long val;

        for(int i=1; i<=n; i++){

            val = pq.top();
            pq.pop();

            while(st.count(val)){
                val = pq.top();
                pq.pop();
            }

            long long s1 = val*2;
            long long s2 = val*3;
            long long s3 = val*5;

            pq.push(s1);
            pq.push(s2);
            pq.push(s3);

            st.insert(val);
        }
        return val;
    }
};