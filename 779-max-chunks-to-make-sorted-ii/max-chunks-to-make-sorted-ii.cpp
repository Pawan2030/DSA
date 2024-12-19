class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {

       int n = arr.size();
       vector<int> prefixmax(n);
       vector<int> suffixmin(n);
       
       int val = -1;
       for(int i=0; i<n; i++){
         val = max(val , arr[i]);
         prefixmax[i] = val;
       }  
       val = INT_MAX;
       for(int i=n-1; i>=0; i--){
        val = min(val , arr[i]);
         suffixmin[i] = val;
       }

       int chunk = 1;

       for(int i=1; i<n; i++){
          if(prefixmax[i-1] <= suffixmin[i]){
            chunk++;
          }
       }
       return chunk;
    }
};