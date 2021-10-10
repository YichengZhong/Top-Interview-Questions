class Solution {
public:
    int arrangeCoins(int n) {
        if(n<1) return 0;
        if(n<=1) return 1;
        int count=1;
        while(1)
        {
            if(n>=count)
            {
                n=n-count;
                count++;
                continue;
            }
            else
            {
                return count-1;
            }
        }
        return -1;
    }
};