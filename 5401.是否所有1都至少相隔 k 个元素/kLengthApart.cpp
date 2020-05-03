class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int numsSize=nums.size();
        for (int i = 0; i < numsSize; ++i)
        {
            if (nums[i] == 1)
            {
                for (int j = 1; j <= k; ++j)
                {
                    if (i + j < numsSize&&nums[i + j] == 1)
                        return false;
                }
                    
                i += k;
            }
        }
        
    return true;
    }
};