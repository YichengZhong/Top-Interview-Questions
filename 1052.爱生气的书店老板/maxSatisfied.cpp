class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        //滑动窗口
        int basesum=0;
        int maxSum=0;
        int sumtemp=0;
        //基础得分
        for(int i=0;i<customers.size();++i)
        {
            if(grumpy[i]==0) basesum=basesum+customers[i];
        }

        for(int i=0;i<=customers.size()-X;++i)
        {
            sumtemp=basesum;
            for(int j=i;j<i+X;++j)
            {
                if(grumpy[j]==1) sumtemp=sumtemp+customers[j];
            }
            maxSum=max(maxSum,sumtemp);
        }

        return maxSum;
    }
};