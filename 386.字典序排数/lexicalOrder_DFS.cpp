class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int>v_out;
        dfs(0,n,v_out);
        return v_out;
    }

    void dfs(int k,int n ,vector<int>&v_out)
    {
        if(k>n)
        {
            return ;  
        }
        if(k!=0)
        {
             v_out.push_back(k);
        }       

        for(int i=0;i<=9;++i)
        {
            if((10*k+i)>0)
            {
                dfs(10*k+i,n,v_out);
            }
        }
    }
};