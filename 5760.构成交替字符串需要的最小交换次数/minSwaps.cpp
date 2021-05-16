class Solution {
public:
    int minSwaps(string s) {
        int one_count=0;
        int zero_count=0;
        for(int i=0;i<s.size();++i)
        {
            if(s[i]=='0') zero_count++;
            else one_count++;
        }

        if(abs(zero_count-one_count)>=2) return -1;
        if(zero_count==one_count) return min(OneFirst(s),ZeroFirst(s));
        if(zero_count>one_count) return ZeroFirst(s);
        return OneFirst(s);
    }

    //1在前面
    int OneFirst(string s)
    {
        int swapcount=0;
        for(int i=0;i<s.size();++i)
        {
            if(i%2==0 && s[i]!='1')
                swapcount++;
        }
        return swapcount;
    }
    //0在前面
    int ZeroFirst(string s)
    {
        int swapcount=0;
        for(int i=0;i<s.size();++i)
        {
            if(i%2==0 && s[i]!='0')
                swapcount++;
        }
        return swapcount;
    }
};