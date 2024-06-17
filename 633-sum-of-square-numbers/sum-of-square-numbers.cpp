class Solution {
public:
    bool judgeSquareSum(int c) {

        int left  = 0;
        int right = sqrt(c);

        while(left <= right){

            long long val = static_cast<long long>(left) * left + static_cast<long long>(right) * right;

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