class Solution {
public:

    long long maximumImportance(int n, vector<vector<int>>& roads) {

        vector<int> vec(n , 0);

        for(auto road : roads){

            int a = road[0];
            int b = road[1];

            vec[a]++;
            vec[b]++;
        }

        sort(begin(vec) , end(vec));
        long long ans = 0;
    
        for(int i = n-1 ; i>=0 ; i--){
           long long temp = (i+1)*1LL*vec[i];
           ans += temp;
        }
        return ans;
    }
};