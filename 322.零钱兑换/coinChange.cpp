class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[amount+1]={0};
        dp[0]=0;
        
        if(0==amount)
        {
            return 0;
        }
        
        int cost=amount+1;
        
        for(int i=1;i<=amount;++i)
        {
            cost=amount+1;
            for(int j=0;j<coins.size();++j)
            {
                if(i-coins[j]>=0)
                {
                    cost=min(cost,dp[i-coins[j]]+1);
                }
            }
            
            dp[i]=cost;
        }
        
        if(dp[amount]>amount)
        {
            return -1;
        }
        
        return  dp[amount];
    }
};