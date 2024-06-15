class Solution {
public:
    typedef pair<int, int> p;

    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {

        int n = profits.size();
        vector<p> arr;

        for (int i = 0; i < n; i++) {

            int pro = profits[i];
            int cap = capital[i];

            arr.push_back({cap, pro});
        }

        sort(begin(arr), end(arr));

        priority_queue<int> pq;
        int i = 0;

        while (k > 0) {

            // take

            while (i < n && w >= arr[i].first) {

                int take = arr[i++].second;
                pq.push(take);
            }

            if(pq.empty())
              break;

            int maxi = pq.top();
            pq.pop();

            w += maxi;
            k--;    
        }

        return w;
    }
};