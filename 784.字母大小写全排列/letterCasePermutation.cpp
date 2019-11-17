class Solution {
public:
    std::unordered_map<char, std::string> m;
    void InitMap()
     {
         m['0'] = "0";
         m['1'] = "1";
         m['2'] = "2";
         m['3'] = "3";
         m['4'] = "4";
         m['5'] = "5";
         m['6'] = "6";
         m['7'] = "7";
         m['8'] = "8";
         m['9'] = "9";
         m['a'] = "aA";
         m['b'] = "bB";
         m['c'] = "cC";
         m['d'] = "dD";
         m['e'] = "eE";
         m['f'] = "fF";
         m['g'] = "gG";
         m['h'] = "hH";
         m['i'] = "iI";
         m['j'] = "jJ";
         m['k'] = "kK";
         m['l'] = "lL";
         m['m'] = "mM";
         m['n'] = "nN";
         m['o'] = "oO";
         m['p'] = "pP";
         m['q'] = "qQ";
         m['r'] = "rR";
         m['s'] = "sS";
         m['t'] = "tT";
         m['u'] = "uU";
         m['v'] = "vV";
         m['w'] = "wW";
         m['x'] = "xX";
         m['y'] = "yY";
         m['z'] = "zZ";
         m['A'] = "aA";
         m['B'] = "bB";
         m['C'] = "cC";
         m['D'] = "dD";
         m['E'] = "eE";
         m['F'] = "fF";
         m['G'] = "gG";
         m['H'] = "hH";
         m['I'] = "iI";
         m['J'] = "jJ";
         m['K'] = "kK";
         m['L'] = "lL";
         m['M'] = "mM";
         m['N'] = "nN";
         m['O'] = "oO";
         m['P'] = "pP";
         m['Q'] = "qQ";
         m['R'] = "rR";
         m['S'] = "sS";
         m['T'] = "tT";
         m['U'] = "uU";
         m['V'] = "vV";
         m['W'] = "wW";
         m['X'] = "xX";
         m['Y'] = "yY";
         m['Z'] = "zZ";
    }

    void Helper(const std::string &digits, string &phone_number, std::vector<std::string> &result) 
    {
        if(phone_number.size() == digits.size())
        {
            result.push_back(phone_number);
        } 
        else 
        {
            for (char c: m[digits[phone_number.size()]]) 
            {
            phone_number.push_back(c);
            Helper(digits, phone_number, result);
            phone_number.pop_back();
            }
        }
    }

    vector<string> letterCasePermutation(string S) 
    {
        if(S.size()==0) 
        {
            return {};
        }
        InitMap();
        std::string phone_number;
        std::vector<std::string> result;
        Helper(S, phone_number, result);
        return result;
    }
};