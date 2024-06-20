class Solution {
public:
     
    bool isPlacedPossible(int mid , vector<int>& pos, int m){
       
       int balls = 1;
       int prev = 0;

       for(int i = 1; i < pos.size(); i++){
           
           if(pos[i] - pos[prev] >= mid){
              balls++;
              prev = i;
           }

           if(balls == m) return true;
       }

       return balls >= m;
    }


    int maxDistance(vector<int>& position, int m) {
        
        int n = position.size();
        sort(begin(position) , end(position));
        int s = 0;
        int e = *max_element(position.begin() , position.end());
        int ans = -1;

        while(s <= e){

            int mid = s + (e-s)/2; //min force is this

            if(isPlacedPossible(mid , position , m)){
                ans = mid;
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
        return ans;
    }
};