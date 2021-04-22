class Solution {
public:
    bool checkIfPangram(string sentence) {
        int numcount[26]={0};

        for(int i=0;i<sentence.size();++i)
        {
            numcount[sentence[i]-'a']++;
        }

        for(int i=0;i<26;++i)
        {
            if(numcount[i]==0) return false;
        }

        return true;
    }
};