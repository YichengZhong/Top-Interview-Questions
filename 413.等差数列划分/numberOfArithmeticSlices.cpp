class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        // 返回结果
        int res = 0;
        int n = nums.size();

        // 忽略小于3的情况
        if (n < 3)
        {
            return res;
        }

        // 等差的结果
        int d = nums[1] - nums[0];
        int cnt = 0;

        for (int i = 2; i < n; ++i)
        {
            if (nums[i] - nums[i-1] == d)
            {
                // 相等情况，累加结果
                ++cnt;
                res += cnt;
            }
            else
            {
                // 不等情况，则刷新等差数组长度的计数
                cnt = 0;
                d = nums[i] - nums[i-1];
            }
        }
        
        return res;
    }
};