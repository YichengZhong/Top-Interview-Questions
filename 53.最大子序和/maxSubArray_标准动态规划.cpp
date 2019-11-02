class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(0==nums.size())
            return 0;
        
        int dp[nums.size()]={0};
        dp[0]=nums[0];
        int result=nums[0];
        
        for(int i=1;i<nums.size();++i)
        {
            dp[i]=(dp[i-1]+nums[i])>nums[i]?(dp[i-1]+nums[i]):nums[i];
            result=(result>dp[i])?result:dp[i];
        }
    
        return result;
        
    }
};