class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        
        int n = arr.size();
       
        int i = 0;
        int j = n-1;

        while(j > 0 && arr[j-1] <= arr[j]){
            j--;
        }

         int cnt = j;

        while(i < j && ( i == 0 || arr[i] >= arr[i-1])){
            
            while(j < n && arr[i] > arr[j]){
                j++;
            }
            cnt = min(cnt , j-i-1);
            i++;
        }

        return cnt == n ? 0 : cnt;
    }
};