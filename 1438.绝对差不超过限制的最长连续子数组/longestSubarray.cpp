class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> s;
        int ans = 0;
        int i = 0;
        for (int j = 0; j < nums.size(); j++) 
        {
            s.insert(nums[j]);
            while (*s.rbegin() - *s.begin() > limit)
            {
                s.erase(s.find(nums[i]));
                i++;
            }
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};