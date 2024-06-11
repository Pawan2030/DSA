class Solution {
public:

    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        
        map<int,int> mp;

        for(int num : arr1){
            mp[num]++;
        }

        int j = 0;

        for(int i=0; i<arr2.size(); i++){
             
             int element = arr2[i];
             int freq = mp[element];

             while(freq--){
                arr1[j++] = element;
                mp[element]--;
             }

        }

        for(auto num : mp){

             int ele = num.first;
             int freq = num.second;

             if(freq == 0)
                continue;
             

             while(freq--){
                arr1[j] = ele;
                mp[ele]--;
                if(j < arr1.size()){
                    j++;
                }
             }
        }

        return arr1;
    }
};