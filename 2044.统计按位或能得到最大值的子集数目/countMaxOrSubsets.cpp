class Solution {
public:
    int ans = 0;
    int countMaxOrSubsets(vector<int>& nums) {
        // 按位或是不减的操作，所以全部 | 起来是最大值
        int sum = 0;
        for(auto p : nums)
        {
            sum |= p;
        }
        dfs(nums, sum, 0, 0);

        return ans;
    }
    void dfs(vector<int>& nums, int& m, int idx, int cur){
        // 剪枝
        if(cur == m)
        {
            ans += 1 << (nums.size() - idx);
            return;
        }
        
        if(idx == nums.size())
        {
            return;
        }
        // 加上这个数
        dfs(nums, m, idx + 1, cur | nums[idx]);
        // 不加这个数
        dfs(nums, m, idx + 1, cur);
    }
};