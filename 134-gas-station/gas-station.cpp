class Solution {
public:

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int n = gas.size();

        int totalGas  = 0;
        int totalCost = 0;

        for(int i=0; i<n; i++){
            totalGas += gas[i];
            totalCost += cost[i];
        }

        if(totalCost > totalGas) return -1;


        int curr  = 0;
        int total = 0;
        int start = 0;

        for(int i=0; i<n; i++){
            
            curr =  curr + gas[i] - cost[i];
            
            if(curr < 0){
                start = i+1;
                curr = 0;
            }
            
        }

        return start;
    }
};