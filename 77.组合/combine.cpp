class Solution {
public:
    
    vector<int> input;
    vector<vector<int>> result;
    vector<int> vc;

    void dfs(int index,int k) 
    {
        if (vc.size() == k) 
        {
            result.push_back(vc);
        }
        for (int i = index; i < input.size(); i++)
        {
            vc.push_back(input[i]);
            dfs(i + 1,k);
            vc.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
         // “剪枝”的前提是排序，升序或者降序均可
        vector<int> nums;
        nums.clear();
        
        for(int i=0;i<n;++i)
        {
            nums.push_back(i+1);
        }
        
        input=nums;
        
        dfs(0,k);
        return result;
        
    }
};