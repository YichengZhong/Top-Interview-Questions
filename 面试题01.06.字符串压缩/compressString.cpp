class Solution {
public:
    string compressString(string S) {
        if (S.size()<=2) return S;
        int pre = 0, later = 0;
        string str;
        while (later <= S.size())
        {
            if (S[pre] == S[later])
                later++;
            else
            {
                str += S[pre] +  to_string(later - pre);
                pre = later; 
            }
        }

        return S.size() <= str.size() ?S: str;
    }
};