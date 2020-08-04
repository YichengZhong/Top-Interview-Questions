class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int out=0;

        int left=0,right=0;

        while(right<=s.size())
        {
            string tmp=s.substr(left,right-left);

            while(!isUnRepeat(tmp))
            {
                left++;
                tmp=s.substr(left,right-left);
            }

            out=max(out,right-left);
            right++;
        }

        return out;
    }

    bool isUnRepeat(string &s)
    {
        unordered_map<char,int>m_count;

        for(int i=0;i<s.size();++i)
        {
            m_count[s[i]]++;

            if(m_count[s[i]]>1)
            {
                return false;
            }
        }

        return true;
    }
};