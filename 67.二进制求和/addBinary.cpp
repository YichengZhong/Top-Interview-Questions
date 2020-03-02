class Solution {
public:
    string addBinary(string a, string b) {
       int lena=a.size();
        int lenb=b.size();
        int lenc=abs(lena-lenb);
        string c(lenc,'0');
        if(lena>lenb)
            b=c+b;
        else
            a=c+a;
        c.resize(a.size(),'0');
        int flag=0;
        for(int i=c.size()-1;i>=0;i--)
        {
            int temp=(int)(a[i]-'0')^(int)(b[i]-'0')^flag;
            c[i]=(char)(temp+'0');
            if((int)(a[i]-'0')+(int)(b[i]-'0')+flag>1)
                flag=1;
            else
                flag=0;
        }
        if(flag)
            c='1'+c;
        return c;

    }
};