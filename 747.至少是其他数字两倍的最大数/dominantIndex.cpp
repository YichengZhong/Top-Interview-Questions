class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        
        int nums_max=nums[0];
        int nums_index=0;
        
        for(int i=0;i<nums.size();++i)
        {
           if(nums[i]>=nums_max)
           {
               nums_max=nums[i];
               nums_index=i;
           }
        }
        
        for(int i=0;i<nums.size();++i)
        {
            if(i!=nums_index)
            {
                if(nums_max>=(2*nums[i]))
                {
                    continue;
                }
                else
                {
                    return -1;
                }
            }
        }
        
        return nums_index;
        
    }
};