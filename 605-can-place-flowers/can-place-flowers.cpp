class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        
        if(n == 0)
          return true;

        int s = f.size();

        for(int i=0; i<s; i++){

            if(f[i] == 0){

                if((i==0 || f[i-1] == 0) && (i == s-1 || f[i+1] == 0)){
                     f[i] = 1;
                     n--;
                     cout<<n<<endl;

                     if(n==0) return true;
                }
            }
        }
        return false;
    }
};