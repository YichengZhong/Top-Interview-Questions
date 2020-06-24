class Solution {
public:
    int maxScore(string s) {
        vector<int>v_zero(s.size()-1,0);
        vector<int>v_one(s.size()-1,0);

        int temp=0;
        for(int i=0;i<s.size()-1;++i)
        {
            if(s[i]=='0')
            {
                temp++;
            } 
            v_zero[i]=temp;
        }

        temp=0;
        for(int i=s.size()-1;i>0;--i)
        {
            if(s[i]=='1')
            {
                temp++;
            } 
            v_one[i-1]=temp;
        }

        int max=0;
        for(int i=0;i<s.size()-1;++i)
        {
            if(max<(v_zero[i]+v_one[i]))
            {
                max=v_zero[i]+v_one[i];
            }
        }

        return max;

    }
};