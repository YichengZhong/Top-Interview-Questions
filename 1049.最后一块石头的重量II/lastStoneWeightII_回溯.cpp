class Solution {
public:
    int sum;
    int sum_half;
    int g_sum_temp;
    int lastStoneWeightII(vector<int>& stones) {
        if(stones.size()==0)
        {
            return 0;
        }

        sum=0;
        for(int i=0;i<stones.size();++i)
        {
            sum=sum+stones[i];
        }

        sum_half=sum/2;

        g_sum_temp=0;

        help(0,0,stones);

        return abs(2*g_sum_temp-sum);
    }

    void help(int index,int sum_temp,vector<int>& stones)
    {
        if(sum_half==g_sum_temp)
        {
            return ;
        }

        if(abs(sum_half-g_sum_temp)>abs(sum_half-sum_temp))
        {
            g_sum_temp=sum_temp;
        }

        for(int i=index;i<stones.size();++i)
        {
            sum_temp=sum_temp+stones[i];
            help(i+1,sum_temp,stones);
            sum_temp=sum_temp-stones[i];
        }
    }
};