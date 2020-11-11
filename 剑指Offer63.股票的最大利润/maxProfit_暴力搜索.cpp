class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //暴力解法
        int maxVaule=0;
        if(prices.size()==0) return 0;

        for(int i=0;i<prices.size()-1;++i)
        {
            for(int j=i+1;j<prices.size();++j)
            {
                if(prices[i]>=prices[j])
                {
                    continue;
                }
                maxVaule=max(maxVaule,prices[j]-prices[i]);
            }
        }

        return maxVaule;
    }
};