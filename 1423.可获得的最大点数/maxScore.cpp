class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int s=0;
        int t=k;

        for(int i=0;i<k;++i)
        {
            s=s+cardPoints[i];
        }

        int maxSum=s;
        for(int i=cardPoints.size()-1;i>=cardPoints.size()-k && t>=1;--i)
        {
            s=s-cardPoints[--t]+cardPoints[i];
            maxSum=max(s,maxSum);
        }
        
        return maxSum;
    }
};
