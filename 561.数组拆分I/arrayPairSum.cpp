class Solution {
public:
    int arrayPairSum(vector<int>& nums) {

        
        sort(nums.begin(),nums.end());
        
        int min_sum=0;
        
        for(int i=0;i<nums.size();i=i+2)
        {
            min_sum=min_sum+nums[i];
        }
        
        return min_sum;
        
    }
};