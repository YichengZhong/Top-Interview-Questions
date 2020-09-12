class Solution {
public:
    vector<int>v_diag;
    string originalDigits(string s) {
        map<char,int>m_strcout;

        for(int i=0;i<s.size();++i)
        {
            m_strcout[s[i]]++;
        }

    }

    //判断是否有0
    void isHasZero(map<char,int> &m_strcout)
    {
        int ZeroCount=0;
        if(m_strcout['z']==0)
        {
            return ;
        }

        ZeroCount=m_strcout['z'];

        m_strcout['z']=m_strcout['z']-ZeroCount;
        m_strcout['e']=m_strcout['e']-ZeroCount;
        m_strcout['r']=m_strcout['r']-ZeroCount;
        m_strcout['o']=m_strcout['o']-ZeroCount;

        for(int i=0;i<ZeroCount;++i)
        {
            v_diag.push_back(0);
        }
    }

    //判断是否有4
    void isHasFour(map<char,int> &m_strcout)
    {
        int FourCount=0;
        if(m_strcout['u']==0)
        {
            return ;
        }

        FourCount=m_strcout['u'];

        m_strcout['f']=m_strcout['f']-FourCount;
        m_strcout['o']=m_strcout['o']-FourCount;
        m_strcout['u']=m_strcout['u']-FourCount;
        m_strcout['r']=m_strcout['r']-FourCount;

        for(int i=0;i<FourCount;++i)
        {
            v_diag.push_back(4);
        }
    }
    
    //判断是否有6
    void isHasSix(map<char,int> &m_strcout)
    {
        int SixCount=0;
        if(m_strcout['x']==0)
        {
            return ;
        }

        SixCount=m_strcout['x'];

        m_strcout['s']=m_strcout['s']-SixCount;
        m_strcout['i']=m_strcout['i']-SixCount;
        m_strcout['x']=m_strcout['x']-SixCount;

        for(int i=0;i<SixCount;++i)
        {
            v_diag.push_back(6);
        }
    }

    //判断是否有8
    void isHasEight(map<char,int> &m_strcout)
    {
        int EightCount=0;
        if(m_strcout['g']==0)
        {
            return ;
        }

        EightCount=m_strcout['g'];

        m_strcout['e']=m_strcout['e']-EightCount;
        m_strcout['i']=m_strcout['i']-EightCount;
        m_strcout['g']=m_strcout['g']-EightCount;
        m_strcout['h']=m_strcout['h']-EightCount;
        m_strcout['t']=m_strcout['t']-EightCount;

        for(int i=0;i<EightCount;++i)
        {
            v_diag.push_back(8);
        }
    }
};