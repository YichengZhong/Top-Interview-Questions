class Solution {
public:
    string reverseWords(string s) 
    {
        reverse(s.begin(),s.end());
        int i=0;
        string ans;
        while(i < s.size())
        {
            while(i < s.size() && s[i]==' ') 
            {
                ++i;
            }

            if(i>=s.size())
                break;

            int a=i;
            while(i < s.size() && s[i]!=' ') 
                ++i;
            string t=s.substr(a,i-a);
            if(t.size()) 
            {
                reverse(t.begin(),t.end());
                if(ans.size()) 
                    ans += ' ';
                ans += t;
            }
        }
        return ans;
    }
};