class Solution {
public:
    int minOperations(string s) {
        //0开头
        int count_Zero=0;
        for(int i=0;i<s.size();++i)
        {
            if(s[i]!='0' && i%2==0)
            {
                count_Zero++;
            }

            if(s[i]!='1' && i%2==1)
            {
                count_Zero++;
            }
        }
        //1开头
        int count_One=0;
        for(int i=0;i<s.size();++i)
        {
            if(s[i]!='1' && i%2==0)
            {
                count_One++;
            }

            if(s[i]!='0' && i%2==1)
            {
                count_One++;
            }
        }

        return count_Zero>count_One?count_One:count_Zero;

    }
};