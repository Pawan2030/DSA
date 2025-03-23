class Solution {
public:

    int trap(vector<int>& height) {
        
        int n = height.size();
        int res = 0;
        vector<int> rightTOLeft(n);
        int maxi  = INT_MIN;

        for(int i=n-1; i>=0; i--){
            maxi= max(height[i], maxi);
            rightTOLeft[i] =maxi; 
        }

        maxi = INT_MIN;

        for(int i=0; i<n; i++){
            maxi = max(maxi , height[i]);
            res += (min(maxi , rightTOLeft[i]) - height[i]);
        }

        return res;
    }
};