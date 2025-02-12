class Solution {
public:
    
    int cal(int num){
        
        int sum = 0;

        while(num > 0){
            
            int digit = num%10;
            num /= 10;
            sum += digit;
        }
        return sum;
    }

    int maximumSum(vector<int>& nums) {
        
        unordered_map<int,int> mp;
        int res = -1;
        int n = nums.size();

        vector<int> pre(n);

        for(int i=0; i<n; i++){
            int sum = cal(nums[i]);
            pre[i] = sum;
        }

        for(int i=0; i<n; i++){

            int sum = pre[i];

            if(mp.find(sum) != mp.end()){
                int val = mp[sum];
                res = max(res , nums[i]+val);
                mp[sum] = max(val , nums[i]);;
            }else{
                mp[sum] = nums[i];
            }
        }

        return res;
    }
};