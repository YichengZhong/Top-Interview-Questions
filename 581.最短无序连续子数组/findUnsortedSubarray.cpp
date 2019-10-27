class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> nums_temp;
        nums_temp=nums;
        
        sort(nums.begin(),nums.end());
        int start=nums.size();
        int end=0;
        for (int i = 0; i < nums.size(); i++) 
        {
            if (nums_temp[i] != nums[i]) 
            {
                start = min(start, i);
                end = max(end, i);
            }
        }
        return (end - start >= 0 ? end - start + 1 : 0);
        
    }
};