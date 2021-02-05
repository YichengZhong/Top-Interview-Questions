class Solution {
public:
    vector<string> getValidT9Words(string num, vector<string>& words) {
        string dig_num[26]={"2","2","2","3","3","3","4","4","4","5","5","5","6","6","6","7","7","7","7","8","8","8","9","9","9","9"};
        vector<string>out;

        for(int i=0;i<words.size();++i)
        {
            string tmp="";

            for(int j=0;j<words[i].size();++j)
            {
                tmp=tmp+dig_num[words[i][j]-'a'];
            }

            if(tmp==num)
            {
                out.push_back(words[i]);
            }
        }

        return out;
    }
};