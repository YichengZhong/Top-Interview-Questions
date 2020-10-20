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

        long x=(long)dividend,y=(long)divisor;
        if(dividend<0)//都改成正数再做
            x=-(long)dividend;
        if(divisor<0)
            y=-(long)divisor;
        long result=0;
        while(x>=y)//代表x里面还能分出y
        {
            long temp=y,res=1;
            while(x>=(temp<<1))//然后开始比较是否大于y的倍数，一次从x里面减去最大的2^n*y
            {
                res<<=1;
                temp<<=1;
            }
            result+=res;//res代表temp里面有多少个y，所以在x减去temp后，res也要加在result里。
            x-=temp;
        }
        
        return sign*result;
    }
};