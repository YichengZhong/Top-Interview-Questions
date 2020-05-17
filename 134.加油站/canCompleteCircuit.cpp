class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int temp = (-1);

        for (int i = 0; i < gas.size(); ++i)
        {
            int gas_now = gas[i];
            int start = i;

            if (gas_now < cost[i])
            {
                continue;
            }


            while (gas_now >= cost[start])
            {
                gas_now = gas_now - cost[start] + gas[(start + 1) % gas.size()];
                start = (start + 1) % gas.size();

                if (i == start)
                {
                    temp = start;
                    return temp;
                }
            }
        }

        return temp;
    }
};