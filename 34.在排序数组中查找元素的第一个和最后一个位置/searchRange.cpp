class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size();
        vector<int> res = {-1, -1};
        // 找左边界
        while (l < r) 
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] < target) 
            {
                l = mid + 1;
            } 
            else 
            {
                r = mid;
            }
        }
        if (l == nums.size() || nums[l] != target) return res;
        
        res[0] = l;
        
        // 找右边界，就是查找最后一个 bad version
        r = nums.size();
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] > target) 
            {
                r = mid;
            } else 
            {
                l = mid + 1;
            }
        }
        
        res[1] = l - 1;
        return res;
        
    }
};