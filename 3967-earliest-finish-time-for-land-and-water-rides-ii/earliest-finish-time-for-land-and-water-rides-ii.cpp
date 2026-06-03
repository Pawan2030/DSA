class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        
        int n = landStartTime.size();
        int m = waterStartTime.size();

        int minLand = INT_MAX;
        int minWar  = INT_MAX;
        int MinWarTime = INT_MAX;
        int minLandTime = INT_MAX;
        
        //land min time
        for(int i=0; i<n; i++){
            minLand = min(minLand , landStartTime[i] + landDuration[i]);
        }

        //water min time
        for(int i=0; i<m; i++){
            minWar = min(minWar , waterStartTime[i]+waterDuration[i]);
            MinWarTime = min(MinWarTime , max(minLand , waterStartTime[i]) + waterDuration[i]);
        }

        for(int i=0; i<n; i++){
            minLandTime = min(minLandTime , max(minWar , landStartTime[i]) + landDuration[i]);
        }

        return min(minLandTime , MinWarTime);
    }
};