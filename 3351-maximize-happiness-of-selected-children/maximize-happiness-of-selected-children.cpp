class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        
    
        sort(begin(happiness) , end(happiness), greater<int>());
        long long maxi = 0;

        for(int i=0; i<k; i++){  
           maxi += max(0 , happiness[i]-i);
        }
        return maxi;
    }
};