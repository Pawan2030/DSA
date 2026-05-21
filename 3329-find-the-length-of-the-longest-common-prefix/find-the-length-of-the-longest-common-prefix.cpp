class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        
        int n1 = arr1.size();
        int n2 = arr2.size();

        unordered_map<int,int> mp;

        for(int num : arr1){

            while(num > 0){
                mp[num]++;
                num = num/10;
            }
        }

        int len = 0;

        for(int num : arr2){

            while(num > 0){ 
               if(mp.find(num) != mp.end()){
                   string st = to_string(num);
                   int size = st.size();
                   len = max(len , size);
                   break;
               }
               num = num/10;
            }
        }

        return len;
    }
};