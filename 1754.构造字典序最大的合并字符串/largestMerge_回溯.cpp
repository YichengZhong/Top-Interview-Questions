class Solution {
public:
    vector<string>mergelist;
    string largestMerge(string word1, string word2) {
        mergelist.clear();
        helpDFS(word1,word2,"");
        sort(mergelist.begin(),mergelist.end());
        return mergelist[mergelist.size()-1];
    }

    void helpDFS(string word1, string word2,string merge)
    {
        mergelist.push_back(merge);

        if(word1.size()>1)
        {
            helpDFS(word1.substr(1),word2,merge+word1[0]);
        }

        if(word1.size()==1)
        {
            helpDFS("",word2,merge+word1[0]);
        }

        if(word2.size()>1)
        {
            helpDFS(word1,word2.substr(1),merge+word2[0]);
        }

        if(word2.size()==1)
        {
            helpDFS(word1,"",merge+word2[0]);
        }
    }
};