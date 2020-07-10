class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int max_sum=0;
        int temp=0;
        for(int i=0;i<nums.size();++i)
        {
            if(nums[i]==1)
            {
                temp=temp+1;
                if(temp>=max_sum)
                {
                    max_sum=temp;
                }
            }
            if(nums[i]==0)
            {
                if(temp>=max_sum)
                {
                    max_sum=temp;
                }
                temp=0;
            }
        }
        
        return max_sum;
        
    }
};