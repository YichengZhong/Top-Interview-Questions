class Solution {
public:
    string s_out;
    string longestDiverseString(int a, int b, int c) {
        vector<char> candidates;
        candidates.clear();

        for (int i = 0; i < a; ++i)
        {
            candidates.push_back('a');
        }

        for (int i = 0; i < b; ++i)
        {
            candidates.push_back('b');
        }

        for (int i = 0; i < c; ++i)
        {
            candidates.push_back('c');
        }

        s_out = "";
        string tmp = "";

        compute(tmp, candidates, a + b + c);

        return s_out;

    }

    void compute(string& tmp, vector<char>& candidates, int len)
    {
        int n = candidates.size();

        if (tmp.find("aaa") == (-1) && tmp.find("bbb") == (-1) && tmp.find("ccc") == (-1))
        {
            if (tmp.size() > s_out.size())
            {
                s_out = tmp;
            }
        }
        else
        {
            return;
        }

        for (int i = 0; i < n; i++)
        {
            if (tmp.size() >= 0 && tmp.size() < len)
            {
                tmp += candidates[i];
                compute(tmp, candidates, len);
                tmp = tmp.substr(0, tmp.size() - 1);//回溯
            }
        }
    }
};