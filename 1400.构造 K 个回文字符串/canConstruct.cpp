class Solution {
public:
    bool canConstruct(string s, int k) {
        map<char,int>m_count;

        for(int i=0;i<s.size();++i)
        {
            if(m_count.find(s[i])==m_count.end())
            {
                m_count[s[i]]=1;
            }
            else
            {
                m_count[s[i]]++;
            }
        }

        map<char,int>::iterator iter;
        int n=0;
        for(iter=m_count.begin();iter!=m_count.end();++iter)
        {
            if(iter->second %2==1 )
            {
                n++;
            }
        }

        if(n>k || s.size()<k)
        {
            return false;
        }

        return true;
        
    }
};