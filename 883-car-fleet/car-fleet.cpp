class Solution {
public:

    int carFleet(int target, vector<int>& pos, vector<int>& speed) {
        
        priority_queue<pair<int,double>> pq;
        int n = pos.size();


        for(int i=0; i<n; i++){

            int position = pos[i];
            double time = (double)(target - position)/speed[i];
            pq.push({position , time});
        }

        int fleet = 0;

        while(pq.size() != 1){

            auto ahead = pq.top(); pq.pop();
            auto behind = pq.top(); pq.pop();

            if(ahead.second >= behind.second){
                pq.push({ahead.first , ahead.second});
            }
            else{
                fleet++;
                pq.push({behind.first , behind.second});
            }
        }
        return fleet + 1;
    }
};