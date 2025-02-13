class Solution {
public:

    int minOperations(vector<int>& nums, int k) {
        
        priority_queue<long long int, vector<long long int>, greater<long long int>> pq;

        for(long long int num : nums){
            pq.push(num);
        }
    
        long long int Operations = 0;

        while(pq.top() < k && pq.size() > 1){

            long long int x = pq.top();
            //cout<<"x-> "<<x<<endl;
            pq.pop();
            long long int y = pq.top();
            // if(y >= k){
            //     break;
            // }
            //cout<<"y-> "<<y<<endl;
            pq.pop();

            long long int newGen = min(x, y) * 2 + max(x, y);
            Operations++;
            pq.push(newGen);
            //cout<<"newGen-> "<<newGen<<endl;
        }

        return Operations;
    }
};