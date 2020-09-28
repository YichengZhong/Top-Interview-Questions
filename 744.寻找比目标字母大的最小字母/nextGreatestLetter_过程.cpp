class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int temp[26]={0};

        for(int i=0;i<letters.size();++i)
        {
            temp[letters[i]-'a']++;
        }

        for(int i=(target-'a'+1);i<26;++i)
        {
            if(temp[i]>0)
            {
                return ('a'+i);
            }
        }

        return ' ';
    }
};