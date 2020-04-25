class Solution {
public:
    string getHappyString(int n, int k)
    {
        vector<char> candidates;
        candidates.clear();

        candidates.push_back('a');
        candidates.push_back('b');
        candidates.push_back('c');

        string tmp="";
        vector<string> ans;
        ans.clear();

        compute(tmp,candidates,ans,n);

        if(k>ans.size())
        {
            return "";
        }

        return ans[k-1];
    }

    void compute(string& tmp, vector<char>& candidates, vector<string>& ans,int len) 
    {        
        int n = candidates.size();        
        for(int i = 0; i < n; i ++)
        {            
            if(tmp.size()==len)
            {
                ans.push_back(tmp);
                return ;
            }

            if(tmp.size() == 0)
            {
                tmp+=candidates[i];
                compute(tmp,candidates,ans,len);
                tmp = tmp.substr(0,tmp.size()-1);//回溯
            }

            if(tmp.size()!=0 && tmp.back()!= candidates[i])
            {
                tmp+=candidates[i];
                compute(tmp,candidates,ans,len);
                tmp = tmp.substr(0,tmp.size()-1);//回溯
            }
        }    
    }        
};