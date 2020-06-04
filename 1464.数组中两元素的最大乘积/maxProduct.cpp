class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()<2)
        {
            return 0;
        }

        sort(nums.begin(),nums.end());
        return (nums[nums.size()-1]-1)*(nums[nums.size()-2]-1);
    }
};