/*
要证（a+b）%c = （a%c+b%c）%c 
即证a+b与a%c+b%c对c同余 
则有c能整除(a+b-a%c-b%c) 
设a=mc+p b=nc+q 
则(a+b-a%c-b%c)=(m+n)c+p+q-p-q=(m+n)c 
则证a+b与a%c+b%c对c同余，证毕
*/

class Solution {
public:
    int fib(int n) {
        if(0==n)
        {
            return 0;
        }

        if(1==n)
        {
            return 1;
        }

        long l_temp_n;
        long l_temp_n_1=1;
        long l_temp_n_2=0;

        for(long i=2;i<=n;++i)
        {
            l_temp_n=l_temp_n_1+l_temp_n_2;
            //l_temp_n=l_temp_n%1000000007;

            l_temp_n_2=l_temp_n_1;
            l_temp_n_1=l_temp_n;
        }

        return l_temp_n;
    }
};