class Solution {
public:
    set<string>str_set;
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {

        helpDFS(s,pairs);

        return *(str_set.begin());
    }

    void helpDFS(string &s,vector<vector<int>>& pairs)
    {
        if(str_set.find(s)!=str_set.end()) return ;
        str_set.insert(s);
        
        for(int i=0;i<pairs.size();++i)
        {
            swap(s[pairs[i][0]],s[pairs[i][1]]);
            helpDFS(s,pairs);
            swap(s[pairs[i][0]],s[pairs[i][1]]);
        }
    }
};