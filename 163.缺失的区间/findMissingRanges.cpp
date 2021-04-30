class Solution
 {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) 
    {
        int n = nums.size();
        int L = lower;
        vector<string> res;
        for (int i = 0; i < n; i ++)
        {
            if (L == nums[i])
                L ++;
            else
            {
                if (L < nums[i] - 1)
                {
                    res.push_back(to_string(L) + "->" + to_string(nums[i] - 1));
                }
                else if (L == nums[i] - 1)
                    res.push_back(to_string(L));
                L = nums[i] + 1;
            }
        }
        if (L < upper)
            res.push_back(to_string(L) + "->" + to_string(upper));
        if (L == upper)
            res.push_back(to_string(L));        
        return res;
    }
};