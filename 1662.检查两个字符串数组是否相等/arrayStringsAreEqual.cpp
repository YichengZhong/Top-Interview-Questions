class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string temp1=getString(word1);
        string temp2=getString(word2);

        return temp1==temp2;
    }

    string getString(vector<string>& word)
    {
        string temp="";
        if(word.size()<=0) return temp;

        for(int i=0;i<word.size();++i)
        {
            temp=temp+word[i];
        }

        return temp;
    }
};