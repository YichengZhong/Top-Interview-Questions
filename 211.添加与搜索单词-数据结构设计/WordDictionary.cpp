class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        wordlist.clear();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        wordlist.push_back(word);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        for(int i=0;i<wordlist.size();++i)
        {
            if(equalstring(wordlist[i],word)) return true;
        }

        return false;
    }

    bool equalstring(string A,string B)
    {
        if(A.size()!=B.size())  return false;

        for(int i=0;i<A.size();++i)
        {
            if(A[i]==B[i]) continue;
            else if(A[i]!=B[i] && (A[i]=='.' || B[i]=='.' )) continue;
            else return false;
        }

        return true;
    }

    vector<string>wordlist;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */