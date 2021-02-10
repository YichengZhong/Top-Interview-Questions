class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        //滑动窗口
        unordered_map<char,int>char_map_s1;
        unordered_map<char,int>char_map_s2;

        if(s1.size()>s2.size()) return false;

        for(int i=0;i<s1.size();++i)
        {
            char_map_s1[s1[i]]++;
            char_map_s2[s2[i]]++;
        }

        if(char_map_s1==char_map_s2) return true;

        for(int i=s1.size();i<s2.size();++i)
        {
            if(char_map_s1 == char_map_s2 ) 
                return true;
            else
            {
                char_map_s2[s2[i]]++;
                char_map_s2[s2[i-s1.size()]]--;

                if(char_map_s2[s2[i-s1.size()]] == 0)
                {
                    auto iter = char_map_s2.find(s2[i-s1.size()]);
                    if(iter != char_map_s2.end())
                        char_map_s2.erase(iter);
                }

                if(char_map_s1 == char_map_s2 ) 
                    return true;
            }
        }
        return false;
    }
};