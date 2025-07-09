class Solution {
public:
/*

amount of gas at ith station = gas[i]
cost i - i+1 = cost[i]


*/
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int totalGas = 0;
        int currGas  = 0;
        int startIdx = 0;
        int n = gas.size();

        for(int i=0; i<n; i++){

            totalGas = totalGas + gas[i] - cost[i];
            currGas  = currGas  + gas[i] - cost[i];

            if(currGas < 0){
                startIdx = i+1;
                currGas  = 0;
            }
        }

        if(totalGas < 0) return -1;
        return startIdx;
    }
};