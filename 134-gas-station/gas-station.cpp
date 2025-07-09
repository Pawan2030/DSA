class Solution {
public:

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int totalGas = 0;
        int currGas  = 0;
        int startIdx = 0;
        int n = gas.size();

        for(int i=0; i<n; i++){

            totalGas = totalGas + gas[i] - cost[i]; // i - i+1 the cost to traval b/w these station is cost[i] so we need to subtract this amout of gas
            currGas = currGas + gas[i] - cost[i];

            if(currGas < 0){
                currGas  = 0;
                startIdx = i+1;
            }

        }

        if(totalGas < 0) return -1; // cost is hight to travel b/w stations so cant possibel to reach again on circuit same station where we started.
        return startIdx;

    }
};