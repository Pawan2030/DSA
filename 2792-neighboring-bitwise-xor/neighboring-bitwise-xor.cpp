class Solution {
public:

    bool doesValidArrayExist(vector<int>& arr) {

        int n = arr.size();
         int cnt = 0;
        // bool res = true;
        // if(n==1 && arr[0] == 1) return false;
        // int cnt = 0;
        // for(int i=0; i<n; i++){
        //    if(arr[i%n] == 1){
        //       if(arr[(i+1)%n] != 1){
        //          if((i==0 && arr[n-1] != 1) || (i > 0 && arr[i-1] != 1)){
        //             res = false;
        //          }
        //       }
        //    }
        // }
        
        for(int i : arr){
            if(i==1) cnt++;
        }
        
        if(cnt%2 != 0) return false;

        return true;
    }
};