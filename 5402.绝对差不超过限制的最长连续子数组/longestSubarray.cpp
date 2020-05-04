class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        if (nums.size() == 0)
            return 0;
        unordered_set<int> lookup;
        int maxlen = 0;
        int left = 0;
        int max = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            while (lookup.size()>0 && (abs(getMin(lookup) - nums[i]) > limit || abs(getMax(lookup) - nums[i]) > limit))
            {
                lookup.erase(nums[left]);
                left++;
            }
            if (lookup.size() > 0 && maxlen < (i - left + 1))
            {
                maxlen = i - left + 1;
            }
            lookup.insert(nums[i]);
        }
        return maxlen;
    }

    int getMin(unordered_set<int> lookup)
    {
        int min = *lookup.begin();
        for (unordered_set<int>::iterator it = lookup.begin(); it != lookup.end(); ++it)
        {
            if (min > (*it))
            {
                min = (*it);
            }
        }
        return min;
    }

    int getMax(unordered_set<int> lookup)
    {
        int max = *lookup.begin();
        for (unordered_set<int>::iterator it = lookup.begin(); it != lookup.end(); ++it)
        {
            if (max < (*it))
            {
                max = (*it);
            }
        }
        return max;
    }
};