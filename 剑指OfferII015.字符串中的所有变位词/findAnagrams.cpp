class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.size()<p.size())
            return {};
        vector<int>out;
        
        //滑动窗口
        unordered_map<char,int>org_map;
        unordered_map<char,int>dest_map;

        for(int i=0;i<p.size();++i)
        {
            org_map[p[i]]++;
        }

        for(int i=0;i<p.size();++i)
        {
            dest_map[s[i]]++;
        }

        if(dest_map==org_map)
        {
            out.push_back(0);
        }

        for(int i=p.size();i<s.size();++i)
        {
            dest_map[s[i]]++;
            dest_map[s[i-p.size()]]--;

            if(dest_map[s[i-p.size()]]==0)
            {
                auto pos = dest_map.find(s[i-p.size()]);
                if (pos != dest_map.end())
                {
                    dest_map.erase(pos);
                }
            }

            if(dest_map==org_map)
            {
                out.push_back(i-p.size()+1);
            }

        }

        return out;
    }
};