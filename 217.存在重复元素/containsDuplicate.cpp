class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int>nums_set;
        nums_set.clear();
        
        int nums_length=nums.size();
        
        if(nums_length==0)
        {
            return false;
        }
        
        for(int i=0;i<nums_length;++i)
        {
            nums_set.insert(nums[i]);
        }
        
        if(nums_set.size()==nums_length)
            return false;
        else
            return true;
    }
};