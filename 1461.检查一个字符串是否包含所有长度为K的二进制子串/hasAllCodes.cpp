class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string>s_cout;
        for(int i=0;i<=(int)s.size()-k;++i)
        {
            string temp=s.substr(i,k);
            s_cout.insert(temp);
        }

        return s_cout.size()==(1<<k);

    }
};