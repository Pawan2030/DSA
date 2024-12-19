class Solution {
public:

    int maxChunksToSorted(vector<int>& arr) {

       int n = arr.size();
       vector<int> mini(n);
       vector<int> maxi(n); 
       int val = -1;

       for(int i=0; i<n; i++){
          val = max(arr[i] , val);
          maxi[i] = val;
       }
       
       val = n;

       for(int i=n-1; i>=0; i--){
          val = min(val , arr[i]);
          mini[i] = val; 
       }

       int chunk = 1;

       for(int i=1; i<n; i++){
          if(maxi[i-1] < mini[i]){
            chunk++;
          }
       }

       return chunk;
    }
};