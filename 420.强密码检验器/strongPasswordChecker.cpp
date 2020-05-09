class Solution {
public:
    int strongPasswordChecker(string s) {
        int res = 0, n = s.size(), lower = 1, upper = 1, digit = 1;
        vector<int> v(n, 0);
        for (int i = 0; i < n;) {
            if (s[i] >= 'a' && s[i] <= 'z') lower = 0;
            if (s[i] >= 'A' && s[i] <= 'Z') upper = 0;
            if (s[i] >= '0' && s[i] <= '9') digit = 0;
            int j = i;
            while (i < n && s[i] == s[j]) ++i;
            v[j] = i - j;
        }
        int missing = (lower + upper + digit);
        if (n < 6)
        {
            int diff = 6 - n;
            res=max(diff,missing);
        } else if(n>20)
        {
            int over = max(n - 20, 0), left = 0;
            res += over;
            for (int k = 1; k < 3; ++k) 
            {
                for (int i = 0; i < n && over >= k; ++i) 
                {
                    if (v[i] < 3 || v[i] % 3 != (k - 1)) continue;
                    v[i] -= k;
                    over -=k;
                }
            }
            for (int i = 0; i < n; ++i)
            {
                if (v[i] >= 3 && over > 0) 
                {
                    int need = v[i] - 2;
                    v[i] -= over;
                    over -= need;
                }
                if (v[i] >= 3) left += v[i] / 3;
            }
            res += max(missing, left);
        }
        else
        {
            int link=0;
            for(int i=v.size()-1;i>=0;i--)
                if(v[i]>=3) link+=v[i]/3;
            res=max(missing,link);
        }
            
        return res;
    }
};