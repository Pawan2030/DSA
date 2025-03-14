class Solution {
public:
    
  
    bool canGiven(int mid , vector<int>& can , long long k){
        
        for(int i=0; i<can.size(); i++){

            k  -= can[i]/mid;
        }

        return k <= 0;
    }



    int maximumCandies(vector<int>& can, long long k) {
        
       int n = can.size();
       int res = 0;
       long long total = accumulate(can.begin() , can.end() , 0LL);
       int sum = *max_element(can.begin() , can.end());

        if(k > total) return res;

         int s = 1;
         int e = sum;

        while(s <= e){

            int mid = s + (e-s)/2;

            if(canGiven(mid , can , k)){
                res = mid;
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }

        return res;
    }
};