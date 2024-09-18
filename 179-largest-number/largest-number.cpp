class Solution {
public:
    string largestNumber(vector<int>& nums) {
        
        int n = nums.size();
        vector<string> arr;

        long long int sum = 0 ;
        for(int &num : nums){
            sum += num;
        }

        if(sum == 0){
            return "0";
        }

        for(int i=0; i<n; i++){
            string s = to_string(nums[i]);
            arr.push_back(s);
        }

        auto comp = [](string &s1 , string &s2){

            return s1 + s2 > s2 + s1 ;
        };

        sort(begin(arr) , end(arr), comp);

        string ans = "";

        for(string &st : arr){
            ans += st;
        }

        return ans;
    }
};