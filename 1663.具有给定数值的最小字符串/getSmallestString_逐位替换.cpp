class Solution {
public:
    string getSmallestString(int n, int k) {
        vector<char>v_out(n,'a');

        int sum=n;

        for(int i=v_out.size()-1;i>=0;--i)
        {
            if(sum==k) break;

            if((k-sum)>=26)
            {
                v_out[i]='z';
            }
            else
            {
                v_out[i]=(k-sum)+'a';
            }

            
            sum=sum+v_out[i]-'a';
        }

        string out="";
        for(int i=0;i<v_out.size();++i)
            out=out+v_out[i];

        return out;     
    }
};