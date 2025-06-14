class Solution {
public:
    int maxArea(vector<int>& h) {
        
        int maxAr = INT_MIN;
        int n = h.size();
        int i = 0;
        int j = n-1;

        while(i < j){

            while(i < j && h[i] < h[j]){
                int ar = (j-i) * min(h[i] , h[j]);
                maxAr = max(maxAr , ar);
                i++;
            }

            while(i < j && h[i] >= h[j]){
                int ar = (j-i) * min(h[i] , h[j]);
                maxAr = max(maxAr , ar);
                j--;
            }

        }
        return maxAr;
    }
};