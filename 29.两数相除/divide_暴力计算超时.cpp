class Solution {
public:
    int divide(int dividend, int divisor) {
        int cout=0;
        int sign=1;

        if((dividend==INT_MIN && divisor==-1)||(dividend==INT_MAX && divisor==1)) return INT_MAX;

        if((dividend==INT_MIN && divisor==1)||(dividend==INT_MAX && divisor==-1)) return INT_MIN;

        if(dividend==0) return 0;

        if(dividend>0 && divisor>0)
        {
            sign=1;
        }
        else if(dividend<0 && divisor<0)
        {
            sign=1;
        }
        else
        {
            sign=(-1);
        }

        dividend = dividend>0 ? -dividend : dividend;
        divisor = divisor>0 ? -divisor : divisor;

        while(dividend<=divisor)
        {
            cout++;
            dividend=dividend-divisor;
        }

        return sign*cout;
    }
};