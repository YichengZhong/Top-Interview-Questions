class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int left=1,right=getMax(piles)+1;

        while(left<right)
        {
            int mid=left+(right-left)/2;
            if(canFinish(piles,mid,H))
            {
                right=mid;
            }
            else
            {
                left=mid+1;
            }
        }

        return left;        
    }
    bool canFinish(vector<int>& piles, int speed,int H)
    {
        int time=0;
        for(int i=0;i<piles.size();++i)
        {
            time=time+timeOf(piles[i],speed);
        }

        return time<=H;
    }

    int timeOf(int n,int speed)
    {
        return (n/speed)+((n%speed>0)?1:0);
    }

    int getMax(vector<int>&piles)
    {
        int maxValue=0;
        for(int i=0;i<piles.size();++i)
        {
            maxValue=max(maxValue,piles[i]);
        }

        return maxValue;
    }
};