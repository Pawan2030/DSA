class Solution {
public:
    
    int minSum(int num){
         
         int sum = 0;
         while(num > 0){
            sum += num%10;
            num /= 10;
         }
         return sum;
    }

    int minElement(vector<int>& nums) {
        
        int sum = INT_MAX;

        for(int num : nums){
            sum = min(sum , minSum(num));
        }
        return sum;
    }
};