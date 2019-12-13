class Solution {
public:
    int romanToInt(string s) {
        int out=0;
        int temp=0;

        map<char,int>m_str_int;
        m_str_int['I']=1;
        m_str_int['V']=5;
        m_str_int['X']=10;
        m_str_int['L']=50;
        m_str_int['C']=100;
        m_str_int['D']=500;
        m_str_int['M']=1000;

        if(s.size()==0)
        {
            return 0;
        }

        out=m_str_int[s[s.size()-1]];
        for(int i=s.size()-2;i>=0;--i)
        {
            if(m_str_int[s[i]]<m_str_int[s[i+1]])
            {
                out=out-m_str_int[s[i]];
            }
            else
            {
                out=out+m_str_int[s[i]];
            }
        }

        return out;
        
    }
};