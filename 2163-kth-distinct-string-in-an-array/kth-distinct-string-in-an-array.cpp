class Solution {
public:

    string kthDistinct(vector<string>& arr, int k) {
        
        unordered_map<string , int> mp;

        for(auto st : arr){
            mp[st]++;
        }

        int cnt = 0;
        string ans = "";

        for(auto st : arr){
            
            if(mp[st] == 1){
                cnt++;
            }
            
            if(cnt == k){
                ans = st;
                return ans;
            }
        }
        return ans;
    }
};