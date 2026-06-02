class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        
        int n = landStartTime.size();
        int m = waterStartTime.size();

        int minland     = INT_MAX;
        int minwar      = INT_MAX;
        int minTimeLand = INT_MAX;
        int minTimeWar  = INT_MAX;

        for(int i=0; i<n; i++){
            minland = min(minland , landStartTime[i] + landDuration[i]);
        }

        for(int i=0; i<m; i++){
            minwar = min(minwar , waterStartTime[i]+waterDuration[i]);
            minTimeLand = min(minTimeLand , max(waterStartTime[i] , minland) + waterDuration[i]);
        }

        for(int i=0; i<n; i++){
            minTimeWar = min(minTimeWar , max(landStartTime[i] , minwar) + landDuration[i]);
        } 

        return min(minTimeLand , minTimeWar);
    }
};