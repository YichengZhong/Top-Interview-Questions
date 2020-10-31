class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long> set;
        for(int i = 0; i < nums.size(); i ++) 
        {
            auto it = set.lower_bound((long) nums[i] - t);
            if(it != set.end() && *it <= (long) nums[i] + t) return true;
            set.insert(nums[i]);
            if(set.size() == k + 1) set.erase(nums[i - k]); //保证滑动窗口
        }
        return false;
    }
};