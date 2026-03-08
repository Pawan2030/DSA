class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> st(nums.begin() , nums.end());
        int ans = 0;

        for(int num : st){

           if(!st.count(num-1)){ 
            int curr = num;
            int cnt  = 1;

            while(st.count(curr+1)){
                curr++;
                cnt++;
            }

            ans = max(ans,cnt);
            }
        }
        return ans;
    }
};