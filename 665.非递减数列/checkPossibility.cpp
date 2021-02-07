class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int flag=0;
        for(int i=0;i<nums.size()-1;++i)
        {
            if(nums[i]<=nums[i+1])
                continue;
            else
            {
                flag++;
                if(flag>1) return false;
                if (i > 0 && nums[i+1] < nums[i-1]) 
                {
                    nums[i + 1] = nums[i];
                }
            }
        }
        
        return true;
    }
};