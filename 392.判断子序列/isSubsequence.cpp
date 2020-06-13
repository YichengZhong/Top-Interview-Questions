class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0,j=0,count=0;
        
        while(i<s.size() && j<t.size() )
        {
            if(s[i]==t[j])
            {
                i++;
                j++;
                count++;                    
            }
            else
            {
                j++;
            }
        }
        
        if(s.size()==count)
        {
            return true;
        }
        
        return false;        
    }
};