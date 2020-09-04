class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        if(bills[0]!=5)
        {
            return false;
        }

        //手上现有钞票,初始一张5块钱
        map<int,int>m_bill;
        m_bill[5]=1;

        for(int i=1;i<bills.size();++i)
        {
            //钱刚好，新增一张5块
            if(bills[i]==5)
            {
                m_bill[5]++;
            }
            else if(bills[i]==10)
            {
                //必须找零一张5块,新增一张10块
                if(m_bill[5]<=0)
                {
                    return false;
                }
                else
                {
                    m_bill[5]--;
                    m_bill[10]++;
                }
            }
            else
            {
                //拿了20块钱
                //优先找零方式1：一张10块，一张5块
                if(m_bill[5]>=1 && m_bill[10]>=1)
                {
                    m_bill[5]--;
                    m_bill[10]--;
                    m_bill[20]++;
                }
                else if(m_bill[5]>=3)
                {
                    m_bill[5]=m_bill[5]-3;
                    m_bill[20]++;
                }
                else
                {
                    return false;
                }
            }
        }

        return true;
        
    }
};