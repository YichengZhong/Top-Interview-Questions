class Solution {
public:
    int res;
    int n;
    void dfs(int val, int idx, vector<int>& nums)
    {
        if (idx == n)
        {
            // 终止递归
            res += val;
            return;
        }
        // 考虑选择当前数字
        dfs(val ^ nums[idx], idx + 1, nums);
        // 考虑不选择当前数字
        dfs(val, idx + 1, nums);
    }
    
    int subsetXORSum(vector<int>& nums) 
    {
        res = 0;
        n = nums.size();
        dfs(0, 0, nums);
        return res;
    }
};