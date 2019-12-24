class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count=0;
        
        int nums_length=0;
        nums_length=nums.size();
        
        if(nums_length==0)
        {
            return 0;
        }
        
        for(int i=0;i<nums_length;++i)
        {
            if(nums[i]!=nums[count])
            {
                count++;
                nums[count] = nums[i];
            }
        }
        count++;
        return count;
    }
};