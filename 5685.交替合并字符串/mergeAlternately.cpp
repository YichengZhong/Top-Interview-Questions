class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int len=min(word1.size(),word2.size());
        string out="";
        
        for(int i=0;i<len;++i)
        {
            out=out+word1[i]+word2[i];
        }
        
        if(len<word1.size())
        {
            for(int i=len;i<word1.size();++i)
            {
                 out=out+word1[i];
            }
        }
        
        if(len<word2.size())
        {
            for(int i=len;i<word2.size();++i)
            {
                 out=out+word2[i];
            }
        }
        
        return out;
    }
};