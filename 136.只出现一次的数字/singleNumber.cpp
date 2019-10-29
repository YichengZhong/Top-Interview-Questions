class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int nums_length=0;
        nums_length=nums.size();
        
        if(0==nums_length)
        {
            return 0;
        }
        
        int temp=nums[0];
        
        for(int i=1;i<nums_length;++i)
        {
            temp=temp^nums[i];
        }
        
        return temp;
        
    }
};