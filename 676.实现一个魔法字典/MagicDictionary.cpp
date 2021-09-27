class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        all_dic.clear();

    }
    
    void buildDict(vector<string> dictionary) {
        all_dic=dictionary;

    }
    
    bool search(string searchWord) {
        for(int i=0;i<all_dic.size();++i)
        {
            if(canTrast(all_dic[i],searchWord))
            {
                return true;
            }
        }

        return false;

    }

    bool canTrast(string dit,string searchWord)
    {
        if(dit.size()!=searchWord.size()) return false;
        if(dit==searchWord) return false;

        int flag=0;
        for(int i=0;i<dit.size();++i)
        {
            if(dit[i]==searchWord[i])
                continue;
            else
            {
                flag++;
            }
            if(flag>1)
                return false;
        }

        return true;
    }

    vector<string>all_dic;


};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */