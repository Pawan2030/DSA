class Solution {
public:

    vector<int> sortArray(vector<int>& nums) {

        //lets implemet by counting sort

        int maxi  = INT_MIN;
        int mini  = INT_MAX;
        unordered_map<int,int> mp;

        for(int num : nums){

            maxi = max(maxi , num);
            mini = min(mini  , num);
            mp[num]++;
        }

        vector<int> ans;

        for(int i = mini; i<= maxi; i++){

            int val  = i;
            int freq = mp[i];

            while(freq--){
                ans.push_back(val);
            }
        }

        return ans;
    }
};