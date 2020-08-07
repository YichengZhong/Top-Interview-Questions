class Solution {
public:
    long out_count=INT_MAX;
    int integerReplacement(int n) {
        dfs(n,0);
        return out_count;

    }

    void dfs(long long n,int count)
    {
        if(n==1)
        {
            out_count=out_count>count?count:out_count;
            return ;
        }

        if(n%2==0)
        {
            dfs(n/2,count+1);
        }
        else
        {
            dfs(n-1,count+1);
            dfs(n+1,count+1);
        }
    }
};