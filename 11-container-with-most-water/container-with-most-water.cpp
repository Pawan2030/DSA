class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int n = height.size();
        int i =0;
        int j = n-1;
        int sum = 0;

        while(i < j){

            sum = max(sum , (min(height[i] , height[j]) * (j-i)));

            if(height[i] > height[j]){
                j--;
            }
            else{
                i++;
            }
        }

        return sum;
    }
};