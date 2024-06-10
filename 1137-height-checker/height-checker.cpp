class Solution {
public:
    int heightChecker(vector<int>& heights) {

        vector<int> arr = heights;
        sort(begin(arr) , end(arr));
        int n = heights.size();

        int cnt = 0;

        //let's compare
        for(int i=0; i<n; i++){

            if(arr[i] != heights[i]){
                cnt++;
            }
        }
        return cnt;
    }
};