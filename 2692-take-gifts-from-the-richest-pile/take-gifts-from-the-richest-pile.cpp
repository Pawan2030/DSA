class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        
        priority_queue<long long> pq;

        for(int &gift : gifts){
            pq.push(gift);
        }

        while(k--){

            long long top = pq.top();
            pq.pop();
            long long sq = sqrt(top);
            pq.push(sq);
        }

        long long sum = 0;

        while(!pq.empty()){

            long long top = pq.top();
            pq.pop();
            sum += top;
        }

        return sum;
    }
};