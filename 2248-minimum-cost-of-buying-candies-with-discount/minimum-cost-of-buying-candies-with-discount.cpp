class Solution {
public:
    int minimumCost(vector<int>& cost) {
        
        int n = cost.size();
        sort(cost.begin() , cost.end());
        int mincost = 0;

        int i = n-1;

        while(i >= 0){

            mincost += cost[i];
            i -= 1;
            cout<<i<<endl;
            if(i >= 0){
               mincost += cost[i];
            }
            i -= 2;
            cout<<i<<endl;
        }
        return mincost;
    }
};