class Solution {
public:
    map<int,int>map_tmp;
    int cuttingRope(int n) {
        return help(n);
    }

    int help(int n)
    {
        if(n<=2)
        {
            return 1;
        }

        if(map_tmp.find(n)!=map_tmp.end())
        {
            return map_tmp[n];
        }

        int res=(-1);
        for(int i=1;i<n;++i)
        {
            res=max(res,max(i*(n-i),i*help(n-i)));
        }

        map_tmp[n]=res;
        return res;
    }
};