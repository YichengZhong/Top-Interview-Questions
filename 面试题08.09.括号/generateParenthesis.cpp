class Solution {
public:
    void backtrade(string sublist,vector<string>& res,int left,int right)
    {
        if(left == 0 && right == 0)
        {
            res.push_back(sublist);
            return;
        }
        if(left > 0)
        {
           backtrade(sublist+"(",res,left-1,right);
        }
        if(left < right)
        {
            backtrade(sublist+")",res,left,right-1);
        }
            
        
    }
    
    
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrade("",res,n,n);
        return res;
        
    }
};