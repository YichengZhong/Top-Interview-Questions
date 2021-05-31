class Solution {
public:
    string maxValue(string n, int x) {
        int l = n.size();
        if (n[0] == '-')
        {
            for (int i = 1; i < l; ++i)
            {
                if (n[i] - '0' > x)
                {
                    n.insert(i, 1, '0' + x);
                    return n;
                }
            }
            n.push_back('0' + x);
            return n;
        }
        else 
        {
            for (int i = 0; i < l; ++i)
            {
                if (n[i] - '0' < x)
                {
                    n.insert(i, 1, '0' + x);
                    return n;
                }
            }
            n.push_back('0' + x);
            return n;
        }
    }
};