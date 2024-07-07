class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {

        int sum = numBottles;

        while(numBottles >= numExchange){
             
            int bottle = numBottles/numExchange;
            int mod = numBottles%numExchange;
            sum += bottle;
            numBottles /= numExchange;
            numBottles += mod;
        }
        return sum;
    }
};