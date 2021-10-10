class Solution {
public:
    int maxProduct(vector<string>& words) {
        if (words.size()==0) return 0;

        vector<int> flags(words.size(), 0);
        for (int i = 0; i < words.size(); ++ i)
        {
            for (char &ch : words[i])
            {
                //flags[i]用来记录字符串words[i]中出现的字符
                flags[i] |= 1 << (ch - 'a');
            }
        }

        int res = 0;
        for (int i = 0; i < words.size(); ++ i)
        {
            for (int j = i + 1; j < words.size(); ++ j)
            {
                //如果两个字符串没有相同的字符
                if ((flags[i] & flags[j]) == 0)
                {
                    int tmp = words[i].length() * words[j].length();
                    res = max(res, tmp);
                }
            }
        }

        return res;
    }
};