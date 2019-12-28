class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
        {
            return "1";
        }

        if(n==2)
        {
            return "11";
        }

        string str_pre="11";
        for(int i=3;i<=n;++i)
        {
            string str_temp="";

            int cout=1;

            for(int j=1;j<str_pre.size();++j)
            {
                if(str_pre[j-1]==str_pre[j])
                {
                    cout++;
                }
                else
                {
                    str_temp=str_temp+to_string(cout)+str_pre[j-1];
                    cout=1;
                }
            }

            str_temp = str_temp + to_string(cout) + str_pre[str_pre.size()-1];
			cout = 1;
            
            str_pre=str_temp;

        }

        return str_pre;
        
    }
};