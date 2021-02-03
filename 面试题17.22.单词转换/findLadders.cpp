class Solution {
public:
    vector<string> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<bool> visited(wordList.size(), false);
        vector<string> result = {beginWord};

        if(hasRoute(beginWord, endWord, wordList, visited, result))
        {
            return result;
        }

        return {};
    }

    bool hasRoute(string& beginWord, string& endWord, vector<string>& wordList, vector<bool>& visited, vector<string>& result) 
    {
        if(beginWord == endWord){ return true; }
        for(int i = 0; i < wordList.size(); ++i)
        {
            if(visited[i] || !jugeSameSize(beginWord, wordList[i])) continue;
            visited[i] = true;
            result.push_back(wordList[i]);
            if(hasRoute(wordList[i], endWord, wordList, visited, result))
            {
                return true;
            }
            result.pop_back();
            //visited[i] = false;
        }
        return false;
    }

    //判断是否只有一个不相似
    bool jugeSameSize(string first, string second)
    {
        if(first.size() != second.size()) { return false; }
        int count = 0;
        for(int i = 0; i < first.size(); ++i)
        {
            if(first[i] != second[i]) 
            {
                count++;
            }
        }
        return count == 1;

    }
};