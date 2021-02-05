class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        vector<int>BitCost(s.size(),0);

        for(int i=0;i<s.size();++i)
        {
            BitCost[i]=abs(s[i]-t[i]);
        }

        int left=0,right=0;

        int tmp=0;
        int maxLen=0;
        while(right!=BitCost.size())
        {
            tmp=tmp+BitCost[right];

            while(tmp>maxCost)
            {
                tmp=tmp-BitCost[left];
                left++;
            }

            right++;
            maxLen=max(maxLen,right-left);
        }

        return maxLen;
    }
    
};