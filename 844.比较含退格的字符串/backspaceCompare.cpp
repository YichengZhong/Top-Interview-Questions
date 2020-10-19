class Solution {
public:
    bool backspaceCompare(string S, string T) {
        string s1=delStr(S);
        string t1=delStr(T);

        return s1==t1;        
    }

    string delStr(string s)
    {
        string str_out="";
        for(int i=0;i<s.size();++i)
        {
            if(s[i]!='#')
            {
                str_out=str_out+s[i];
            }
            else if(s[i]=='#' && str_out.size()>=1)
            {
                str_out.pop_back();
            }
        }

        return str_out;
    }
};