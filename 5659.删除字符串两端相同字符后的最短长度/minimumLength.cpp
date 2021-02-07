class Solution {
public:
    int minimumLength(string s) 
    {
        int l = 0, r = s.size() - 1;

        while(l < r)
        {
            if(s[l]!=s[r]) break;
            while(l<r-1 && s[l+1]==s[r])l++;
            while(r>l+1 && s[r-1]==s[l])r--;
            if(r-l+1>=2&&l<s.size()-1){l++;r--;}
        }
        return r-l+1;
    }
};