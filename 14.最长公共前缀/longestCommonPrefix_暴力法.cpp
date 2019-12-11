class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        
        if (strs.size() == 0)
            return string();
        else if (strs.size() == 1)
            return strs[0];
        
        string ret;
        for (int i = 0; i < strs[0].size(); ++i) 
        {
            for (int j = 0; j < strs.size(); ++j) 
            {
            if (strs[0][i] != strs[j][i])
                return ret;
            }
        ret += strs[0][i];
        }
        return ret;        
    }
};