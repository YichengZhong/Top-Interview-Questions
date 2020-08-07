class Solution 
{
    public:    
    void compute(int start, int target, vector<int>& tmp, vector<int>& candidates, vector<vector<int>>& ans) 
    {        
        int n = candidates.size();        
        for(int i = start; i < n; i ++)
        {            
            if(target > 0)
            {                
                tmp.push_back(candidates[i]);                
                compute(i, target-candidates[i], tmp, candidates, ans);                
                tmp.pop_back();            
            }            
            else if(target < 0)                
                return;            
            else
            {                
                ans.push_back(tmp);                
                return;            
            }       
        }    
    }        
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {        
        vector<vector<int>> ans;        
        vector<int> tmp;                
        int v;                
        sort(candidates.begin(), candidates.end());        
        compute(0, target, tmp, candidates, ans);                
        return ans;    
    }
};

