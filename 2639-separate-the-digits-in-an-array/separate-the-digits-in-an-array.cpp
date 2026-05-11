class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans;

        for(int &num : nums){
            
            stack<int> st;

            while(num > 0){
                int digit = num%10;
                num /= 10;
                st.push(digit);
            }

            while(!st.empty()){
                ans.push_back(st.top());
                st.pop();
            }
        }

        return ans;
    }
};