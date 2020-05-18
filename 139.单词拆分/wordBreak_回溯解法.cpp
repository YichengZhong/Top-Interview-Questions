class Solution {
public:
    map<int,bool>m_str;
    bool wordBreak(string s, vector<string>& wordDict) {
        return word_Break_help(s,wordDict, 0);
    }

    bool word_Break_help(string s, vector<string>& wordDict, int start)
    {
        if(start==s.size())
        {
            return true;
        }

        if(m_str.find(start) != m_str.end())
        {
            return m_str[start];
        }

        for(int end=start+1;end<=s.size();++end)
        {
            if (wordindict(s.substr(start, end-start),wordDict)&& word_Break_help(s, wordDict,end)) 
            {
                return m_str[start] = true;
            }
        }

        return m_str[start]=false;
    }

    bool wordindict(string s,vector<string>& wordDict)
    {
        vector<string>::iterator iter;
        iter = find(wordDict.begin(), wordDict.end(),s);
 
        if(iter != wordDict.end())
        {
            return true;
        }

        return false;
    }
    
    
};