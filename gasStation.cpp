class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(gas.size() == 0) return -1;
        if(gas.size() == 1) return gas[0] >= cost[0] ? 0:-1;
        int start = 0;
        bool second = false;
        int i = 1 % gas.size();
        int gas_total = gas[0] - cost[0];
        while(true)
        {
            if(gas_total < 0 && !second)
            {
                start = i;
                gas_total = gas[i] - cost[i];
            }
            else if(gas_total < 0 && second)
                return -1;
            else
            {
                gas_total += gas[i] - cost[i];
            }
            ++i;
            if(i == gas.size())
            {
                second = true;
                i = 0;
            }
            if(i == start && gas_total >= 0)
                return start;
        }
    }
};
