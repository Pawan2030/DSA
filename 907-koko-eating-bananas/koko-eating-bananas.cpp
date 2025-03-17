class Solution {
public:
    int n;

    bool is_Possible_To_eat_Mid_Banana_in_h_hour(int mid, vector<int>& piles, int h){

        long long banana_Eating_time = 0;

        for(int i=0; i<n; i++){
            if(piles[i] % mid == 0){
                banana_Eating_time += (piles[i]/mid);
            }
            else{
                 banana_Eating_time += ((1LL*piles[i]/(1LL*mid))+1);
            }
        }

        return banana_Eating_time <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        
        n = piles.size();
        int minEat = 1;
        int maxEat = *max_element(begin(piles) , end(piles));

        int res = maxEat;

        while(minEat <= maxEat){

            int mid = minEat + (maxEat - minEat)/2;

            if(is_Possible_To_eat_Mid_Banana_in_h_hour(mid , piles , h)){
                res = mid;
                maxEat = mid-1;
            }
            else{
                minEat = mid+1;
            }
        }
        return res;
    }
};