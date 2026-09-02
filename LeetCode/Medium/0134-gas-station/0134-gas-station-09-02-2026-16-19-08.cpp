class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // figure our the toal gas and total cost of one circle 
        int n = gas.size();
        int totalGas = accumulate(gas.begin(), gas.end(), 0);
        int totalCost = accumulate(cost.begin(), cost.end(), 0);

        if(totalGas < totalCost)return -1; // we can never complete a circle

        int idx =0;
        int tank =0;

        for(int i=0; i<n; i++){
            tank += gas[i] - cost[i];

            if(tank < 0){
                tank =0;
                idx = i+1;
            }
        }
        return idx;
    }
};