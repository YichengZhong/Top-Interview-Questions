class Solution {
public:
    int rangeBitwiseAnd(int m, int n) 
    {
        if(m == INT_MAX)
        {
            return m;
        }

        int out=m;

        for(int i=m+1;i<=n;++i)
        {
            out=out&i;
            if(out == 0 ||  i == INT_MAX)
            {
                break;
            }
        }
        return out;
    }
};