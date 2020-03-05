class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int>prices_benfits;
        
        if(prices.size()==0)
            return 0;
        
        for(int i=0;i<prices.size()-1;++i)
        {
            prices_benfits.push_back(prices[i+1]-prices[i]);
        }
        
        int max_benfits=0;
        int temp_benfits=0;
        
        for(int i=0;i<prices_benfits.size();++i)
        {
            if(temp_benfits+prices_benfits[i]>0)
            {
                temp_benfits=temp_benfits+prices_benfits[i];
            }
            else
            {
                temp_benfits=0;
            }
            
            if(temp_benfits>max_benfits)
            {
                max_benfits=temp_benfits;
            }
        }
        
        return max_benfits;
        
    }
};