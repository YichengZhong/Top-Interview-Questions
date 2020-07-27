class Solution {
public:
    int findClosest(vector<string>& words, string word1, string word2) {
        int word1_index=(-1);
        int word2_index=(-1);

        int tmp=words.size();
        if(tmp==0)
        {
            return 0;
        }

        for(int i=0;i<words.size();++i)
        {
            if(words[i]==word1)
            {
                word1_index=i;
            }

            if(words[i]==word2)
            {
                word2_index=i;
            }

            if(word1_index==(-1) || word2_index==(-1))
            {
                continue;
            }

            tmp=min(tmp,abs(word1_index-word2_index));
        }

        return tmp;


    }
};