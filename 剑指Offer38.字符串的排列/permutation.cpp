class Solution {
public:
    vector<string> v_str_out;
    vector<string> permutation(string s) {
        v_str_out.clear();
        helpDFS(0,s,v_str_out);

        set<string>si(v_str_out.begin(), v_str_out.end());
        v_str_out.assign(si.begin(), si.end());

        return v_str_out;
    }

    void helpDFS(int index,string s,vector<string> &v_str_out)
    {
        if(index>=s.size())
        {
            v_str_out.push_back(s);
        }

        for(int i=index;i<s.size();++i)
        {
            swap(s[i],s[index]);
            helpDFS(index+1,s,v_str_out);
            swap(s[i],s[index]);
        }
    }
};