class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(0==nums.size())
            return 0;
        
        int temp=nums[0],result=nums[0];
        for(int i=1;i<nums.size();++i)
        {
            if(temp>0)
            {
                temp=temp+nums[i];
            }
            else
            {
                temp=nums[i];
            }
            
            result=(result>temp?result:temp);
        }
        
        return result;
        
    }
};