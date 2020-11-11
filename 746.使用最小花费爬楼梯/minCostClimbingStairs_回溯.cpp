class Solution {
public:
    int minValue;
    int minCostClimbingStairs(vector<int>& cost) {
        minValue=INT_MAX;

        helpDFS(0,0,cost);
        helpDFS(1,0,cost);

        return minValue;
    }

    void helpDFS(int index,int sum ,vector<int>& cost)
    {
        if(index>=cost.size())
        {
            minValue=min(minValue,sum);
            return ;
        }

        if(sum>minValue)
        {
            return ;
        }
        helpDFS(index+1,sum+cost[index],cost);
        helpDFS(index+2,sum+cost[index],cost);
    }
};