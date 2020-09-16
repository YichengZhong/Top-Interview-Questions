class Solution {
public:
    vector<int> lexicalOrder(int n) {
        //暴力解法
        vector<string>v_out;
        v_out.clear();

        for(int i=1;i<=n;++i)
        {
            v_out.push_back(to_string(i));
        }

        sort(v_out.begin(),v_out.end());

        vector<int>v_out_2;
        for(int i=0;i<v_out.size();++i)
        {
            v_out_2.push_back(atoi(v_out[i].c_str()));
        }

        return v_out_2;
    }
};