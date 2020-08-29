class Solution {
public:
    int maximumSwap(int num) {
        string str_num=to_string(num);

        if(str_num.size()<2)
        {
            return num;
        }

        string str_num_big=str_num;
        sort(str_num_big.begin(),str_num_big.end());
        reverse(str_num_big.begin(),str_num_big.end());

        if(str_num_big==str_num)
        {
            return num;
        }

        int index=0;
        string c_index="";
        for(int i=0;i<str_num.size();++i)
        {
            if(str_num[i]!=str_num_big[i])
            {
                index=i;
                c_index=str_num_big[i];
                break;
            }
        }

        int index_temp=str_num.find_last_of(c_index);
        char c_temp=str_num[index_temp];
        str_num[index_temp]=str_num[index];
        str_num[index]=c_temp;

        int out=stoi(str_num);
        return out;
    }
};