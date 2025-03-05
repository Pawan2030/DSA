class Solution {
public:
    long long coloredCells(int n) {
        
        long long add = 4;

        long long color = 1;

        if(n == 1) return color;

        for(int i=2; i<=n; i++){
            color += add;
            add   += 4;
        }
        return color;
    }
};