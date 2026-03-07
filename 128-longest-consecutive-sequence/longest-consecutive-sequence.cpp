class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        priority_queue<int, vector<int>, greater<int>> pq;
        int res = 0;

        for(int &num : nums){
            pq.push(num);
        }

        while(pq.size()){

            int cnt = 1;
            int num = pq.top();
            pq.pop();

            while(pq.size() && num+1 == pq.top()){
                cnt++;
                num = pq.top();
                pq.pop();
                while(pq.size() && num == pq.top()){
                    pq.pop();
                }
            }

            res = max(res , cnt);
        }

        return res;
    }
};