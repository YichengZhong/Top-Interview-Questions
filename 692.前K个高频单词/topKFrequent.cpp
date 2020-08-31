class Solution {
public:
    map<string,int>m_str_count;
    vector<string> topKFrequent(vector<string>& words, int k) {
        for(int i=0;i<words.size();++i)
        {
            if(m_str_count.find(words[i])==m_str_count.end())
            {
                m_str_count[words[i]]=1;
            }
            else
            {
                m_str_count[words[i]]++;
            }
        }

        vector<int>v_count;
        v_count.clear();

        for(auto it=m_str_count.begin();it!=m_str_count.end();++it)
        {
            v_count.push_back(it->second);
        }

        sort(v_count.begin(),v_count.end());
        reverse(v_count.begin(),v_count.end());

        int cout=v_count[k-1];
        vector<string>v_str;

        for(auto it=m_str_count.begin();it!=m_str_count.end();++it)
        {
            if(it->second>=cout)
            {
                v_str.push_back(it->first);
            }
        }

        return v_str;

    }
};