class Solution {
public:
    vector<string> v_out;
    vector<string> generateParenthesis(int n) {
        v_out.clear();
        help("",n,n);
        return v_out;        
    }

    void help(string tmp,int left,int right)
    {
        if(left==0 && right==0)
        {
            v_out.push_back(tmp);
            return ;
        }
        if(left>0)
        {
            help(tmp+"(",left-1,right);
        }

        if(right>left)
        {
            help(tmp+")",left,right-1);
        }
    }
};