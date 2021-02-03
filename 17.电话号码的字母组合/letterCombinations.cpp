class Solution {
public:
    std::unordered_map<char, std::string> m;
    vector<string>v_out;
    vector<string> letterCombinations(string digits) 
    {
        if(digits=="") return {};
        
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";

        helpDFS(0,digits,"");

        return v_out;

    }

    void helpDFS(int index,string digits,string tmp)
    {
        if(index>=digits.size())
        {
            v_out.push_back(tmp);
            return ;
        }

        for(int i=0;i<m[digits[index]].size();++i)
        {
            helpDFS(index+1,digits,tmp+m[digits[index]][i]);
        }
    }
};