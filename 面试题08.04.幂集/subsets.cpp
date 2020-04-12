public:
    vector<int> input;
    int SizeCount;
    vector<vector<int>> result;
    //vector<int> vc;

    void dfs(int index, vector<int> vc) 
    {
        if (vc.size() <= SizeCount) 
        {
            result.push_back(vc);
        }
        for (int i = index; i < input.size(); i++)
        {
            vc.push_back(input[i]);
            dfs(i + 1,vc);
            vc.pop_back();
        }
    }
    
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        // “剪枝”的前提是排序，升序或者降序均可
        vector<int> vc;
        sort(nums.begin(), nums.end());
        this->input = nums;
        this->SizeCount = nums.size();
        dfs(0,vc);
        return result;
        
    }