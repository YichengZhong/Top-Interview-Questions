class Solution {
public:
    int climbStairs(int n) 
    {
        return help(n);
    }
    
    int help(int n)
    {
        if(n==0)
            return 0;
        else if (n==1)
            return 1;
        else if(n==2)
            return 2;
        else
            return help(n-1)+help(n-2);
    }
};