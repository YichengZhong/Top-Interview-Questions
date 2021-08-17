class Solution {
public:
    bool checkRecord(string s) {
        if(s.find("LLL")!=(-1)) return false;

        int count=0;
        for(int i=0;i<s.size();++i)
        {
            if(s[i]=='A')
            {
                count++;
            }

            if(count>=2) return false;
        }

        return true;

    }
};