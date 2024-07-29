class Solution {
public:

    int numTeams(vector<int>& rating) {

        int n = rating.size();
        int count = 0;

        if(n < 3) return count;

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                for(int k = j+1; k<n; k++){

                    if(rating[i] < rating[j] && rating[j] < rating[k]){
                        count++;
                    }
                    else if(rating[i] > rating[j] && rating[j] > rating[k]){
                        count++;
                    }
                }

            }
        }
        return count;
    }
};