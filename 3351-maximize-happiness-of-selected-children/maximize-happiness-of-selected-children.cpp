class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        
        function comp = [](int &a, int &b){
            return a > b;
        };

        sort(begin(happiness) , end(happiness), comp);
        long long maxi = 0;

        for(int i=0; i<k; i++){  
           maxi += max(0 , happiness[i]-i);
        }
        return maxi;
    }
};