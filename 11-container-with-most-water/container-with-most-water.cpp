class Solution {
public:
    int maxArea(vector<int>& height) {

        int i = 0;
        int j = height.size()-1;

        int res = 0;

        while(i < j){

            int small;

            if(height[i] < height[j]){
                small = height[i];
                i++;
            }
            else{
                small = height[j];
                j--;
            }

            res = max(res , (small * (j-i+1)));
        }
        return res;
    }
};