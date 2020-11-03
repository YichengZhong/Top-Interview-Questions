class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<string>v_findstr;
        v_findstr.clear();

        for(int i=0;i<26;++i)
        {
            char temp=('a'+i);
            string str_temp="";

            for(int j=0;j<k;++j)
            {
                str_temp=str_temp+temp;
            }
            v_findstr.push_back(str_temp);
        }

        while(findstr(s,v_findstr))
        {
            findstr(s,v_findstr);
        }
        return s;
    }

    bool findstr(string &s,vector<string>&v_findstr)
    {
        for(int i=0;i<v_findstr.size();++i)
        {
            int pos = s.find(v_findstr[i]);
            if(pos!=(-1)) 
            {
                s = s.erase(pos,v_findstr[i].size());
                return true;
            }
                
        }
        return false;
    }
};