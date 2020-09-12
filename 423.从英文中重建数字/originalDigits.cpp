class Solution {
public:
    vector<int>v_diag;
    string originalDigits(string s) {
        map<char,int>m_strcout;

        for(int i=0;i<s.size();++i)
        {
            m_strcout[s[i]]++;
        }

        //一个字母可以确认
        isHasZero(m_strcout);
        isHastwo(m_strcout);
        isHasFour(m_strcout);
        isHasSix(m_strcout);
        isHasEight(m_strcout);

        //两个字母可以确认
        isHasOne(m_strcout);
        isHasThree(m_strcout);
        isHasFive(m_strcout);
        isHasSeven(m_strcout);
        isHasNine(m_strcout);

        sort(v_diag.begin(),v_diag.end());

        string temp="";
        for(int i=0;i<v_diag.size();++i)
        {
            temp=temp+to_string(v_diag[i]);
        }

        return temp;
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

    //判断是否有2
    void isHastwo(map<char,int> &m_strcout)
    {
        int TwoCount=0;
        if(m_strcout['w']==0)
        {
            return ;
        }

        TwoCount=m_strcout['w'];

        m_strcout['t']=m_strcout['t']-TwoCount;
        m_strcout['w']=m_strcout['w']-TwoCount;
        m_strcout['o']=m_strcout['o']-TwoCount;

        for(int i=0;i<TwoCount;++i)
        {
            v_diag.push_back(2);
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

    //判断是否有1
    void isHasOne(map<char,int> &m_strcout)
    {
        int OneCount=0;
        if(m_strcout['o']==0)
        {
            return ;
        }

        OneCount=m_strcout['o'];
        m_strcout['o']=m_strcout['o']-OneCount;
        m_strcout['n']=m_strcout['n']-OneCount;
        m_strcout['e']=m_strcout['e']-OneCount;

        for(int i=0;i<OneCount;++i)
        {
            v_diag.push_back(1);
        }

    }

    //判断是否有3
    void isHasThree(map<char,int> &m_strcout)
    {
        int ThreeCount=0;
        if(m_strcout['t']==0)
        {
            return ;
        }

        ThreeCount=m_strcout['t'];
        m_strcout['t']=m_strcout['t']-ThreeCount;
        m_strcout['h']=m_strcout['h']-ThreeCount;
        m_strcout['r']=m_strcout['r']-ThreeCount;
        m_strcout['e']=m_strcout['e']-ThreeCount;
        m_strcout['e']=m_strcout['e']-ThreeCount;

        for(int i=0;i<ThreeCount;++i)
        {
            v_diag.push_back(3);
        }

    }

    //判断是否有5
    void isHasFive(map<char,int> &m_strcout)
    {
        int FiveCount=0;
        if(m_strcout['f']==0)
        {
            return ;
        }

        FiveCount=m_strcout['f'];
        m_strcout['f']=m_strcout['f']-FiveCount;
        m_strcout['i']=m_strcout['i']-FiveCount;
        m_strcout['v']=m_strcout['v']-FiveCount;
        m_strcout['e']=m_strcout['e']-FiveCount;

        for(int i=0;i<FiveCount;++i)
        {
            v_diag.push_back(5);
        }

    }

    //判断是否有7
    void isHasSeven(map<char,int> &m_strcout)
    {
        int SevenCount=0;
        if(m_strcout['s']==0)
        {
            return ;
        }

        SevenCount=m_strcout['s'];
        m_strcout['s']=m_strcout['s']-SevenCount;
        m_strcout['e']=m_strcout['e']-SevenCount;
        m_strcout['v']=m_strcout['v']-SevenCount;
        m_strcout['e']=m_strcout['e']-SevenCount;
        m_strcout['n']=m_strcout['n']-SevenCount;

        for(int i=0;i<SevenCount;++i)
        {
            v_diag.push_back(7);
        }

    }

    //判断是否有9
    void isHasNine(map<char,int> &m_strcout)
    {
        int NineCount=0;
        if(m_strcout['i']==0)
        {
            return ;
        }

        NineCount=m_strcout['i'];
        m_strcout['n']=m_strcout['n']-NineCount;
        m_strcout['i']=m_strcout['i']-NineCount;
        m_strcout['n']=m_strcout['n']-NineCount;
        m_strcout['e']=m_strcout['e']-NineCount;

        for(int i=0;i<NineCount;++i)
        {
            v_diag.push_back(9);
        }

    }

    
};