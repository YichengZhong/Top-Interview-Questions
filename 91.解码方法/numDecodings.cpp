class Solution {
public:
    int count;
    
    int numDecodings(string s) 
    {
        count=0;

        if(s[0]=='0')
        {
            return count;
        }

        word_Break(s,0);
        
        return count;
    }
    
    bool word_Break(string s, int start) {
        if (start == s.size())
        {
            count++;
            return true;
        }
        for (int end = start + 1; end <= s.size(); end++)
        {
            string str_temp=s.substr(start,end-start);  
            int int_temp= atoi(str_temp.c_str());
            if((int_temp>=1 && int_temp <=26 && str_temp[0]!='0'))
            {
                word_Break(s, end);
            }
        }
        return false;
    }
};