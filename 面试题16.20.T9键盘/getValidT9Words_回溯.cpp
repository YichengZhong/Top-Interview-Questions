class Solution {
public:
    std::unordered_map<char, std::string> m;
    vector<string>v_out;
    vector<string> getValidT9Words(string num, vector<string>& words) {

        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";

        helpDFS(0,num,"",words);

        return v_out;
    }

    void helpDFS(int index,string digits,string tmp,vector<string>& words)
    {
        if(index>=digits.size())
        {
            auto iter=find(words.begin(),words.end(),tmp);
            if(iter!=words.end())  v_out.emplace_back(tmp);
            return ;
        }

        for(int i=0;i<m[digits[index]].size();++i)
        {
            helpDFS(index+1,digits,tmp+m[digits[index]][i],words);
        }
    }
    
};