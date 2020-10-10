class Solution {
public:
    int minCount;
    int flag;
    int coinChange(vector<int>& coins, int amount) {
        minCount=amount;
        flag=0;

        sort(coins.begin(),coins.end());
        help(coins,amount,0,0,0);

        return flag==0?(-1):minCount;
    }

    void help(vector<int> coins, int amount, long long sum ,int count,int index)
    {
        if(sum==amount)
        {
            flag=1;
            minCount=min(minCount,count);
        }

        if(sum>amount)
        {
            return ;
        }

        for(int i=index;i<coins.size();++i)
        {
            help(coins,amount, sum+coins[i] ,count+1,i);
        }
    }
};