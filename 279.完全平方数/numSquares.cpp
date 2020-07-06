class Solution {
public:
    int numSquares(int n) {
        vector<int> v_sqr_table;
        v_sqr_table.clear();
        
        int temp=1;
        
        while(temp*temp<=n)
        {
            v_sqr_table.push_back(temp*temp);
            temp++;            
        }
        
        
        int dp[n+1];
        dp[0]=0;
        
        int cost=5;
        
        for(int i=1;i<=n;++i)
        {
            cost=5;
            for(int j=0;j<v_sqr_table.size();++j)
            {
                if(i-v_sqr_table[j]>=0)
                {
                    cost=min(cost,dp[i-v_sqr_table[j]]+1);
                }
            }
            
            dp[i]=cost;
        }
        
        return  dp[n];
        
        
        
    }
};