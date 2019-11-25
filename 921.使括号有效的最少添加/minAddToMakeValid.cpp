class Solution {
public:
    int minAddToMakeValid(string S) {

        int left=0,right=0;

        int out=0;

        for(int i=0;i<S.size();++i)
        {
            if(S[i]=='(')
            {
                left++;
            }

            if(S[i]==')')
            {
                if(left>0)
                {
                    left--;
                }
                else
                {
                    right++;
                }
            }
        }

        out=left+right;

        return out;
        
    }
};