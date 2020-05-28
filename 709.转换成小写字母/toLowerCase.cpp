class Solution {
public:
    string toLowerCase(string str) {
        string out_str=str;
        for(int i=0;i<out_str.size();++i)
        {
            if(out_str[i]>='A'&&out_str[i]<='Z')
            {
                out_str[i]=out_str[i]+32;
            }
        }
        
        return out_str;
    }
};