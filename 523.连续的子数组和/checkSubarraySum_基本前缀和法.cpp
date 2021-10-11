class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size()<2) 
            return false;
        vector<int>prex_sum(nums.size()+1,0);

        int temp=0;
        for(int i=0;i<nums.size();++i)
        {
            temp=temp+nums[i];
            prex_sum[i+1]=temp;
        }

        for(int i=2;i<prex_sum.size();++i)
        {
            for(int j=0;j<prex_sum.size()-i;++j)
            {
                if((prex_sum[j+i]-prex_sum[j])%k==0)
                {
                    return true;
                }
            }
        }

        return false;
    }
};