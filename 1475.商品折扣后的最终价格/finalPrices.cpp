class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int>prices_discount;
        vector<int> v_out;

        for(int i=0;i<prices.size()-1;++i)
        {
            int flag=0;
            for(int j=i+1;j<prices.size();++j)
            {
                if(prices[j]<=prices[i])
                {
                    prices_discount.push_back(prices[j]);
                    flag=1;
                    break;
                }
            }

            if(flag!=1)
            {
                prices_discount.push_back(0);
            }
            
        }

        prices_discount.push_back(0);

        for(int i=0;i<prices.size();++i)
        {
            v_out.push_back(prices[i]-prices_discount[i]);
        }

        return v_out;

    }
};