class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        unordered_map<int,int>ballcount;
        
        for(int i=lowLimit;i<=highLimit;++i)
        {
            int temp=getNumSum(i);
            
            ballcount[temp]++;
        }
        
        int count=0;
        for(auto iter=ballcount.begin();iter!=ballcount.end();++iter)
        {
            count=max(count,iter->second);
        }
        
        return count;

    }
    
    int getNumSum(int Num)
    {
        if(Num<10) return Num;
        
        int sum=0;
        while(Num>0)
        {
            sum=sum+Num%10;
            Num=Num/10;
        }
        
        return sum;
    }
};