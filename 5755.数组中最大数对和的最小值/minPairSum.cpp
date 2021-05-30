class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int maxValue=0;
        for(int i=0;i<nums.size();++i)
        {
            maxValue=max(maxValue,nums[i]+nums[nums.size()-1-i]);
        }
        return maxValue;
    }
};