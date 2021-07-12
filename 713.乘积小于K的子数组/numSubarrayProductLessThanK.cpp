class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();

        // 子数组的个数
        int res = 0;
        int l = 0;

        // 当前的乘积
        int prod = 1;
        for (int r = 0; r < n; ++r)
        {
            prod *= nums[r];
            
            // 一旦超过k则不断移动l来减少
            while (prod >= k && l <= r)
            {
                prod /= nums[l];
                ++l;
            }
            // l到r范围 比如取l+1~r 也肯定满足<k，条件，那么这里就有  r-l+1 个子数组数量
            res += r - l + 1;
        }

        return res;
    }
};