class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        if(s==t) return false;

        unordered_map<char,int>s_map;
        unordered_map<char,int>t_map;

        for(int i=0;i<s.size();++i)
        {
            s_map[s[i]]++;
            t_map[t[i]]++;
        }

        return s_map==t_map;
    }
};