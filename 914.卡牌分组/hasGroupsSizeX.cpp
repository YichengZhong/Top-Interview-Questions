class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        if(deck.size()<=1)
        {
            return false;
        }

        map<int,int>deck_cout;

        for(int i=0;i<deck.size();++i)
        {
            deck_cout[deck[i]]++;
        }

        vector<int>v_index;

        for(auto it=deck_cout.begin();it!=deck_cout.end();++it)
        {
            v_index.push_back(it->second);
        }

        int gcd_temp=getGcg(v_index);

        return gcd_temp>=2?true:false;
    }

    //求解最大公因数
    int getGcg(vector<int>v_index)
    {
        int gcd_temp=100000;
        for(int i=0;i<v_index.size();++i)
        {
            for(int j=i+1;j<v_index.size();++j)
            {
                int temp=gcd(v_index[i],v_index[j]);
                gcd_temp=min(gcd_temp,temp);

                if(gcd_temp<=1)
                {
                    return 1;
                }
            }
        }

        return gcd_temp ;
    }
};