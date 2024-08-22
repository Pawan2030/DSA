class Solution {
public:

    int maxScoreSightseeingPair(vector<int>& values) {
        
        int n = values.size();
        int score = INT_MIN;
        int left  = values[0];
        //int pos = 0;

        for(int i=1; i<n; i++){

            score = max(score , left + values[i]  - i);
            left = max(left , values[i]+i);    
        }
        
        return score;
    }
};