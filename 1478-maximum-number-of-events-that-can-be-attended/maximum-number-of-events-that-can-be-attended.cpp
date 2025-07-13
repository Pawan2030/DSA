class Solution {
public:
    
    typedef pair<int,int> P;

    struct custom{
        bool operator() (P p1, P p2){
            if(p1.second < p2.second){
                return false;
            }
            return true;
        }
    };

    int maxEvents(vector<vector<int>>& events) {
        
        int n = events.size();
        int maxevent = 0;

        priority_queue<P , vector<P> , custom> pq;
        sort(begin(events) , end(events));

        int minDay = INT_MAX;
        int maxDay = INT_MIN;

        for(int i=0; i<n; i++){
            minDay = min(minDay , events[i][0]);
            maxDay = max(maxDay , events[i][1]);
        }

        int idx = 0;

        while(minDay <= maxDay){
            
            // on MinDay All event we are putting in min-Queue
            while(idx < n && events[idx][0] <= minDay){
                pq.push({events[idx][0] , events[idx][1]});
                idx++;
            }

            while(!pq.empty() && pq.top().second < minDay){
                pq.pop();
            }
            
            if(!pq.empty()){
               maxevent += 1;
                pq.pop();
            }
            minDay += 1;
        }

        return maxevent;
    }
};