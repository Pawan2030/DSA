class Solution {
public:

    int trap(vector<int>& height) {

        int n = height.size();

        vector<int> right(n);
        vector<int> left(n);

        int maxi = INT_MIN;
         
        //right to left
        for(int i=n-1; i>=0; i--){

            maxi = max(height[i] , maxi);
            right[i] = maxi;
        }

        maxi =INT_MIN;

        //left to right
        for(int i=0; i<n; i++){
            maxi = max(maxi , height[i]);
            left[i] = maxi;
        }

        int ans = 0;

        for(int i=0; i<n; i++){

            ans += (min(left[i] , right[i]) - height[i]);
        }

        return ans;
    }
};