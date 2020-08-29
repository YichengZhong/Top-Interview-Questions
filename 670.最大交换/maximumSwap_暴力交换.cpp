class Solution {
public:
    int maximumSwap(int num) {
        string str_num=to_string(num);
        int out=num;

        if(str_num.size()<2)
        {
            return num;
        }

        for(int i=0;i<str_num.size()-1;++i)
        {
            for(int j=i+1;j<str_num.size();++j)
            {
                char c_temp=str_num[i];
                str_num[i]=str_num[j];
                str_num[j]=c_temp;
            
                int temp = stoi(str_num);
                out=max(out,temp);

                c_temp=str_num[i];
                str_num[i]=str_num[j];
                str_num[j]=c_temp;
            }
        }

        return out;
    }
};