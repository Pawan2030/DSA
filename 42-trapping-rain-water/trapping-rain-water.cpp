class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        if(n==0) return 0;
        vector<int> rightToLeft(n,0);

        rightToLeft[n-1] = height[n-1];
        int rightMax = INT_MIN;

        for(int i=n-2; i>=0; i--){
            rightToLeft[i] = max(rightMax , rightToLeft[i+1]);
            rightMax = max(rightMax , height[i]);
        }

        int res = 0;
        int maxLeft = height[0];

        for(int i=1; i<n; i++){
       
            int ans = min(maxLeft , rightToLeft[i]) - height[i];
            maxLeft = max(maxLeft , height[i]);

            if(ans > 0){
                res += ans;
            }
        }

        return res;
    }
};