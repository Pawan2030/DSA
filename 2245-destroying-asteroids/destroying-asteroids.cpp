class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        
        int n = asteroids.size();
        sort(asteroids.begin() , asteroids.end());
        long long int m = mass;

        for(int i=0; i<n; i++){
             
             if(asteroids[i] > m){
                return false;
             }else{
                m += asteroids[i];
             }
        }
        return true;
    }
};