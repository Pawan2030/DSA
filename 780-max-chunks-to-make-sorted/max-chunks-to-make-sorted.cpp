class Solution {
public:

    int maxChunksToSorted(vector<int>& arr) {
 
        int sum = 0;
        int n = arr.size();
        vector<int> temp(n , 0);

        for(int i=0; i<n; i++){
            sum += i;
            temp[i] = sum;
        }
        
        int cum = 0;
        int chunk = 0;

        for(int i=0; i<n; i++){
            cum = cum + arr[i];
            cout<<"ADD->>"<<cum<<endl;
            if(cum == temp[i]){
                cout<<"cum->"<<cum<<endl;
                cout<<"temp->"<<temp[i]<<endl;
                chunk++;
            }
        }
        return chunk;
    }
};

//        int n = arr.size();
//        vector<int> mini(n);
//        vector<int> maxi(n); 
//        int val = -1;

//        for(int i=0; i<n; i++){
//           val = max(arr[i] , val);
//           maxi[i] = val;
//        }
       
//        val = n;

//        for(int i=n-1; i>=0; i--){
//           val = min(val , arr[i]);
//           mini[i] = val; 
//        }

//        int chunk = 1;

//        for(int i=1; i<n; i++){
//           if(maxi[i-1] < mini[i]){
//             chunk++;
//           }
//        }

//        return chunk;
//     }
// };