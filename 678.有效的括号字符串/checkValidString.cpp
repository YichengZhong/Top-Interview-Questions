class Solution {
public:
    bool checkValidString(string s) {
        vector<string>v_str;

        for(int i=0;i<s.size();++i)
        {
            if(v_str.size()==0 && (s[i]=="*" || s[i]=="(")
            {
                v_str.push_back(s[i]);
            }
            else if(v_str.size()==0 && s[i]==")")
            {
                return false;
            }
            else if(s[i]=="*")
            {
                if(v_str.back()=="(")
                {
                    v_str.pop_back();
                }
                else if(v_str.back()==")")
                {
                    return false;
                }
                else
                {
                    v_str.push_back(s[i]);
                }
            }
            else if(s[i]==")")
            {
                if(v_str.back()=="(")
                {
                    v_str.pop_back();
                }
                else if(v_str.back()==")")
                {
                    return false;
                }
                else
                {
                     v_str.pop_back();
                }
            }
            else
            {
                if(v_str.back()=="(")
                {
                    v_str.pop_back();
                }
            }
        }

    }
};