class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count=1;
        if(nums.size()<2)
        {
            return nums.size();
        }

        int fast=1,slow=1;
        for(int fast=1;fast<nums.size();++fast)
        {
            if(nums[fast]==nums[fast-1])
            {
                count++;
            }
            else
            {
                count=1;
            }

            if(count<=2)
            {
                nums[slow]=nums[fast];
                slow++;
            }
        }
        
        return slow;
    }
};