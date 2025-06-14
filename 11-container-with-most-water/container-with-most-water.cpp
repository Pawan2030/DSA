class Solution {
public:
    int maxArea(vector<int>& h) {
        
        int maxAr = INT_MIN;
        int n = h.size();
        int i = 0;
        int j = n-1;

        while(i < j){
            
            int temp;

            if(h[i] < h[j]){
                temp = h[i];
                i++;
            }
            else{
                temp = h[j];
                j--;
            }

            maxAr = max(maxAr , (j-i+1)*temp);
        }

        
        return maxAr;
    }
};