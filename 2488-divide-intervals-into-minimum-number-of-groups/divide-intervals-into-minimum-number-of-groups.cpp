class Solution {
public:

    int minGroups(vector<vector<int>>& arr) {
        
        priority_queue<int , vector<int> , greater<int>> pq;
        sort(begin(arr) , end(arr));

        for(int i = 0; i<arr.size(); i++){

            int s = arr[i][0];
            int e = arr[i][1];

            if(!pq.empty() && s > pq.top()){
                pq.pop();
            }
            
            pq.push(e);
        }

        return pq.size();
    }
};