class Solution {
public:
    vector<vector<string>> v_out;
    vector<vector<string>> partition(string s) {
        v_out.clear();

        vector<string>temp;
        temp.clear();

        word_Break_help(s,0,temp);

        return v_out;
        
    }

     bool word_Break_help(string s, int start,vector<string>temp)
     {
        if(start==s.size())
        {
            v_out.push_back(temp);
            return true;
        }

        for(int end=start+1;end<=s.size();++end)
        {
            if (isPalindrome(s.substr(start, end-start)))
            {
                temp.push_back(s.substr(start, end-start));
                word_Break_help(s, end,temp);
                temp.pop_back();
            }
        }

        return false;
     }

     bool isPalindrome(string s) {
        if(!s.size())
        {
            return true;
        }

        int i=0,j=s.size()-1;
        for(;i<j;)
        {
            if(s[i]==s[j])
            {
                ++i;
                --j;
            }
            else
            {
                return false;
            }
        }

        return i>=j?true:false;
    }
};