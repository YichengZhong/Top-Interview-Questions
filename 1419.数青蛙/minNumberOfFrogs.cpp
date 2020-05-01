class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int c,r,o,a,k;
        c = 0; r = 0; o = 0; a = 0;k = 0;

        int res = 0;
        for(int i=0;i<croakOfFrogs.size();++i)
        {
            if(croakOfFrogs[i] == 'c')
            {
                if(k > 0)
                {
                    k--;
                }
                else
                {
                    res++;
                }
                c++;
            }
            else if(croakOfFrogs[i] == 'r')
            {
                c--;
                r++;
            }
            else if(croakOfFrogs[i] == 'o')
            {
                r--;
                o++;
            }
            else if(croakOfFrogs[i] == 'a')
            {
                o--;
                a++;
            }
            else if(croakOfFrogs[i] == 'k')
            {
                a--;
                k++;
            }
            if(c < 0 || r < 0 || o < 0 || a < 0)
            {
                break;
            }
        }

        if(c != 0 || r != 0 || o != 0 || a != 0)
        {
            return -1;
        }
        
        return res;
    }
};