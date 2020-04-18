class Solution {
public:
    string printBin(double num) {
        string res="0.";
        int i=0;
        while(i<32 && num>0)
        {
            num=2*num;
            if(num>=1)
            {
                res+='1';
                num-=1;
            }
            else
            {
                res+='0';
            }
            ++i;
        }
        return num?"ERROR":res;

    }
};