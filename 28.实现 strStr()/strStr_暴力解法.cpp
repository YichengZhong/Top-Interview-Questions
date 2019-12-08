class Solution {
public:
    int strStr(string haystack, string needle) {
        if(""==needle)
        {
            return 0;
        }
        
        if(""==haystack)
        {
            return -1;
        }
        
        for(int i=0;i<haystack.size();++i)
        {
            int first=i;
            int k=0;
            for(int j=i;k<needle.size();++j,++k)
            {
                if(haystack[j]!=needle[k])
                {
                    break;
                }
            }
            if(k==needle.size())
            {
                return first;
            }
        }
        
        return -1;
        
    }
};