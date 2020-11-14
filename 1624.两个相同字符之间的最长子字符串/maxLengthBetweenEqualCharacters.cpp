class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        map<char,vector<int>>m_s;

        for(int i=0;i<s.size();++i)
        {
            if(m_s.find(s[i])==m_s.end())
            {
                vector<int>temp;
                temp.clear();

                temp.push_back(i);

                m_s[s[i]]=temp;
            }
            else
            {
                m_s[s[i]].push_back(i);
            }
        }

        int out=(-1);

        for(auto iter=m_s.begin();iter!=m_s.end();++iter)
        {
            if(iter->second.size()>=2)
            {
                int temp=(iter->second)[iter->second.size()-1]-(iter->second)[0]-1;
                out=max(out,temp);
            }
        }

        return out;
    }
};