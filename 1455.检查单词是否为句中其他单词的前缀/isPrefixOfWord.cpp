class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
         istringstream ss(sentence);
        string str;
        for (int i = 1; ss >> str; i ++)
            if (str.find(searchWord) == 0) return i;
        return -1;

    }
};