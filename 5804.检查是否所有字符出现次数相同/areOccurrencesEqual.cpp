class Solution {
public:
    bool areOccurrencesEqual(string s) {
        int count[26]={0};
        
        for(int i=0;i<s.size();++i)
        {
            count[s[i]-'a']++;
        }
        
        int flag=0;
        for(int i=0;i<26;++i)
        {
            if(count[i]!=0 && flag==0)
            {
                flag=count[i];
            }
            
            if(count[i]!=0 && count[i]!=flag && flag>0)
            {
                return false;
            }
        }
        
        return true;

    }
};