class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int>m_map;

        for(int i=0;i<arr.size();++i)
        {
            m_map[arr[i]]++;
        }

        set<int>m_count;
        for(auto it=m_map.begin();it!=m_map.end();++it)
        {
            m_count.insert(it->second);
        }

        if(m_count.size()==m_map.size())
        {
            return true;
        }

        return false;

    }
};