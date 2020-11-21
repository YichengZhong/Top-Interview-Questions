class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size()) return false;

        vector<int>v_word1(26,0);
        vector<int>v_word2(26,0);

        for(int i=0;i<word1.size();++i)
        {
            v_word1[word1[i]-'a']++;
        }

        for(int i=0;i<word2.size();++i)
        {
            v_word2[word2[i]-'a']++;
        }

        for (int i = 0; i < 26; ++i)
            if ((v_word1[i] == 0) ^ (v_word2[i] == 0))
                return false;

        sort(v_word1.begin(), v_word1.end());
        sort(v_word2.begin(), v_word2.end());

        if(v_word1!=v_word2) return false;
        
        return true;
    }
};