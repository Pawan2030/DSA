class Solution {
public:
    
    bool sorted(int i , int j , vector<int>& arr){
        
        sort(arr.begin()+i , arr.begin()+j+1);

        for(int k = i; k<=j; k++){
            cout<<arr[k]<<endl;
        }
        cout<<"new"<<endl;

        for(int k = i; k <= j; k++){
            if(arr[k] != k) return false;
        }
        return true;
    }

    int maxChunksToSorted(vector<int>& arr) {

       int n = arr.size();
       int i = 0;
       int j = 0;
       int chunk = 0;

       while(i < n && j < n){  
           if(sorted(i , j , arr)){
              chunk++;
              i = j+1;
           }  
           j++;
       }
       return chunk;
    }
};