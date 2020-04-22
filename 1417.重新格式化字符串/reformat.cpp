class Solution {
public:
    string reformat(string s) {
        string out="";

        if(s.size()==0)
        {
            return "";
        }

        vector<char>v_num;
        vector<char>v_char;
        
        v_num.clear();
        v_char.clear();

        for(int i=0;i<s.size();++i)
        {
            if(s[i]>='0'&&s[i]<='9')
            {
                v_num.push_back(s[i]);
            }

            if(s[i]>='a'&&s[i]<='z')
            {
                v_char.push_back(s[i]);
            }
        }

        int nums=v_num.size();
        int char_nums=v_char.size();

        if(abs(nums-char_nums)>1)
        {
            return "";
        }

        if(v_num.size() > v_char.size()) 
        {
            for(int i = 0;i < v_char.size();i++) 
            {
                out += v_num[i];
                out += v_char[i];
            }
            out += v_num[v_num.size() - 1];
        } 
        else if(v_num.size() < v_char.size())
        {
            for(int i = 0;i < v_num.size();i++)
            {
                out += v_char[i];
                out += v_num[i];
            }
        out += v_char[v_char.size() - 1];
        } 
        else 
        {
          for(int i = 0;i < v_num.size();i++) 
            {
             out += v_num[i];
             out += v_char[i];
             }
    
        }
        return out;
    }
};