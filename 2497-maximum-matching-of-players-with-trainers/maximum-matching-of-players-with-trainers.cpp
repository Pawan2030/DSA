class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int p_size = players.size();
        int t_size = trainers.size();
        sort(begin(trainers), end(trainers));
        sort(begin(players), end(players));
        int cnt = 0;

        int p = 0;
        int t = 0;

        while(p < p_size && t < t_size ){

            if(players[p] <= trainers[t]){
                cnt++;
                p++;
                t++;
            }
            else if(players[p] > trainers[t]){
                t++;
            }
        }

        return cnt;
    }
};