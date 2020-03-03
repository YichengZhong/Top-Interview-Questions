class Solution {
public:
    vector<int> input;
    int SizeCount;
    vector<vector<int>> result;
    vector<int> vc;

    void dfs(int index) 
    {
        if (vc.size() <= SizeCount) 
        {
            result.push_back(vc);
        }
        
        for (int i = index; i < input.size(); i++)
        {
            if (i > index && input[i - 1] == input[i])
            {
                continue;
            }
            
            vc.push_back(input[i]);
            dfs(i + 1);
            vc.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
         // “剪枝”的前提是排序，升序或者降序均可
        sort(nums.begin(), nums.end());
        this->input = nums;
        this->SizeCount = nums.size();
        dfs(0);
        return result;
        
    }
};