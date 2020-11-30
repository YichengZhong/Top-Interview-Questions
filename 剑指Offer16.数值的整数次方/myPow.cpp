class Solution {
public:
    double myPow(double x, int n) {
        if(n==0 || x==1)
        {
            return 1;
        }

        if(n>0)
        {
            return help(x,(long long)n);
        }
        else
        {
            return help(1/x,-(long long)(n));
        }
        
    }

    double help(double x,long long n)
    {
        if(n==1)
        {
            return x;
        }

        double tmp=help(x,n/2);

        if(n%2==0)
        {
            return tmp*tmp;
        }
        else
        {
            return tmp*tmp*x;
        }
    }
};