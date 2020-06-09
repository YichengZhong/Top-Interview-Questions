class Solution {
public:
    int count;
    int translateNum(int num) {
        string str_num=to_string(num);
        count=0;

        word_Break_help(str_num,0);

        return count;

    }

    void word_Break_help(string s, int start)
     {
        if(start==s.size())
        {
            count++;
            return ;
        }

        for(int end=start+1;end<=s.size();++end)
        {
            if (isVaildNums(s.substr(start, end-start)))
            {
                word_Break_help(s, end);
            }
        }
     }

     bool isVaildNums(string s) {
        if(!s.size())
        {
            return true;
        }

        if(s.size()>1 && s[0]=='0')
        {
            return false;
        }

        int int_s=atoi(s.c_str());

        if(int_s>=0&&int_s<=25)
        {
            return true;
        }

        return false;
    }
};