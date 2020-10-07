class Solution {
public:
    string str_out;
    long long int_out;
    string removeKdigits(string num, int k) {
        //可以改成从num里面，按照序列取num.size()-k个数字进行组合最小
        str_out="";
        int_out=INT_MAX;

        if(num.size()==k)
            return "0";

        help(num,"",0,num.size()-k);
        return str_out;
    }

    void help(string num,string temp,int index,int count)
    {
        if(temp.size()==count)
        {
            int_out=min(int_out,stoll(temp));
            str_out=to_string(int_out);
        }

        for(int i=index;i<num.size();++i)
        {
            help(num,temp+num[i],i+1,count);
        }
    }

};