class Solution {
public:
    string convertToTitle(int n) {
        string str_out="";
        
        if(n==0)
        {
            return "";
        }
        
        while(n!=0)
        {
            int temp=n;
            int mod=n%26;
            char c_temp;
            if(mod==0)
            {
                c_temp='Z';
                n--;
            }
            else
            {
                c_temp='A'+mod-1;
            }
            str_out=str_out+c_temp;
            n=n/26;
        }
        
        reverse(str_out.begin(),str_out.end());
        
        return str_out;
        
    }
};