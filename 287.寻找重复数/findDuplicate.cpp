class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int result =0;
        for (int i = 0; i < nums.size(); i++) 
        {
            int index = abs(nums[i]) - 1;
            nums[index] = -nums[index];
            if (nums[index] > 0) 
            {
                result=index + 1;
            }
        }
        return result;
        
    }
};