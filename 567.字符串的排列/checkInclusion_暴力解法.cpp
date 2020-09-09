class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size())
        {
            return false;
        }

        vector<string>v_s1;
        v_s1.clear();
        help(s1,0,v_s1);

        for(int i=0;i<v_s1.size();++i)
        {
            if(s2.find(v_s1[i])!=(-1))
            {
                return true;
            }
        }

        return false;      

    }

    void help(string &s1,int index,vector<string>&v_s1)
    {
        if(index>=s1.size())
        {
            v_s1.push_back(s1); ;
        }

        for(int i=index;i<s1.size();++i)
        {
            swap(s1[i],s1[index]);
            help(s1,index+1,v_s1);
            swap(s1[i],s1[index]);
        }
    }
};