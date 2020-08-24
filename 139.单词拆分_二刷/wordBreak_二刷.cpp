class Solution {
public:
    map<int,bool>g_map;
    bool wordBreak(string s, vector<string>& wordDict) {
        return helpDFS(0,s,wordDict);

    }

    bool helpDFS(int start,string s,vector<string>& wordDict)
    {
        if(start==s.size())
        {
            return true;
        }

        if(g_map.find(start) != g_map.end())
        {
            return g_map[start];
        }

        for(int end=start+1;end<=s.size();++end)
        {
            if(isWordInDict(s.substr(start,end-start),wordDict) && helpDFS(end,s,wordDict) )
            {
                g_map[start] = true;
                return true;
            }
        }

        g_map[start] = false;
        return false;
    }

    bool isWordInDict(string str,vector<string>& wordDict)
    {
        vector<string>::iterator iter;
        iter = find(wordDict.begin(), wordDict.end(),str);
 
        if(iter != wordDict.end())
        {
            return true;
        }

        return false;
    }
};