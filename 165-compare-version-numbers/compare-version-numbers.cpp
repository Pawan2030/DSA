class Solution {
public:


    void solve(string &version ,  vector<int>& arr){

        stringstream ss(version);
        string token;

        while(getline(ss , token , '.')){
            int num = stoi(token);
            arr.push_back(num);
        }

    }

    
    int compareVersion(string version1, string version2) {

       
        vector<int> arr1;
        vector<int> arr2;

        solve(version1 , arr1);
        solve(version2 , arr2);
        
        int size = max(arr1.size() , arr2.size());

        while(arr1.size() < size){
            arr1.push_back(0);
        }

        while(arr2.size() < size){
            arr2.push_back(0);
        }

        for(int i=0 ; i<size; i++){   
           cout<<i<<"->"<<arr1[i]<<endl;
        }

        for(int i=0 ; i<size; i++){   
           cout<<i<<"->"<<arr2[i]<<endl;
        }

        for(int i=0 ; i<size; i++){
             
            if(arr1[i] > arr2[i]){
                return 1;
            }
            else if(arr1[i] < arr2[i]){
                return -1;
            }
        }

        return 0;
        
    }
};