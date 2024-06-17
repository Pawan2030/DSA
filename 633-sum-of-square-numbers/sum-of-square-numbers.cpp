class Solution {
public:
    bool judgeSquareSum(int c) {

        long long left  = 0;
        long long right = sqrt(c);

        while(left <= right){

            //long long val = static_cast<long long>(left) * left + static_cast<long long>(right) * right;
            long long val = left * left + right * right;

            if(val == c){
                return true;
            }
            else if(val > c){
                right--;
            }
            else{
                left++;
            }
        }
        return false;
    }
};