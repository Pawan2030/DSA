class Solution {
public:

    vector<int> arrayRankTransform(vector<int>& arr) {
        
        vector<int> temp = arr;
        sort(begin(temp) , end(temp));
        unordered_map<int,int> mp;

        int pos = 1;
        
        for(int i = 0; i<temp.size(); i++){

            if(i > 0 && temp[i-1] != temp[i]){
               pos++;
               mp[temp[i]] = pos; 
            }
            else{
                mp[temp[i]] = pos;
            }
        }

        for(int i = 0; i<arr.size(); i++){
     
            int pos = mp[arr[i]];
            arr[i]  = pos;
        }

        return arr;
    }
};