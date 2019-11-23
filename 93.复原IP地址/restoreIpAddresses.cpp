class Solution {
public:
    vector<vector<string>>v_out;
    vector<string>v_str_out;
    vector<string> restoreIpAddresses(string s) {
        v_out.clear();
        vector<string> v_temp;
        v_str_out.clear();

        if(s.size()<4 || s.size()>16)
        {
            return v_str_out;
        }

        word_Break(s, 0, v_temp, 0);

        for (int i = 0; i < v_out.size(); ++i)
        {
            string temp = "";
            bool flag=true;
            for (int j = 0; j < v_out[i].size(); ++j)
            {
                if(v_out[i][j].size()>1&& atoi(v_out[i][j].c_str())==0)
                {
                    flag=false;
                    break;
                }
                else if(v_out[i][j].size()>1&& v_out[i][j][0]=='0')
                {
                    flag=false;
                    break;
                }
                else{
                    temp = temp + "." + v_out[i][j];
                }
            }

            if(true==flag)
            {
                 temp.erase(0, 1);
                 v_str_out.push_back(temp);
            }
        }

        return v_str_out;

    }

    bool word_Break(string s, int start, vector<string> temp, int count) {
        if (start == s.size() && temp.size()==4)
        {
            v_out.push_back(temp);
            return true;
        }
        for (int end = start + 1; end <= s.size(); end++)
        {
            string str_temp = s.substr(start, end - start);
            int int_temp = atoi(str_temp.c_str());
            if ((int_temp >= 0 && int_temp <= 255 ))
            {
                temp.push_back(str_temp);
                count++;
                word_Break(s, end, temp, count);
                temp.pop_back();
                count--;
            }
        }
        return false;
    }
};