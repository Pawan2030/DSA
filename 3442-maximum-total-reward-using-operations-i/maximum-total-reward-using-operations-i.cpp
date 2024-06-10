class Solution {
public:

    int n;
    int maxi = INT_MIN;
    bool t[2001][2001];

    void solve(int index , vector<int>& arr , int sum){
        
        //base case
        if(index >= n || sum > 2000){
            maxi = max(maxi , sum);
            return;
        }

        if(t[index][sum]){
            return;
        }
        
        //take

        if(arr[index] > sum){
            solve(index+1 , arr ,  arr[index] + sum);
        }

        //skip
        solve(index+1 , arr , sum);

        t[index][sum] = true;

    }

    int maxTotalReward(vector<int>& rewardValues) {
        
        int sum = 0;
        n = rewardValues.size();
        sort(begin(rewardValues) , end(rewardValues));
        memset(t , 0 , sizeof(t));

        solve(0 , rewardValues , sum);

        return maxi;
    }
};