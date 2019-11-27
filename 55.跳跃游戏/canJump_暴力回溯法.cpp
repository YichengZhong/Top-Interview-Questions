class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        return canJumpFromPosition(0, nums);
    }

    bool canJumpFromPosition(int position, vector<int>& nums) {
        if (position == nums.size() - 1)
         {
            return true;
        }

        int nums_size=nums.size()-1;

        int furthestJump = min((position + nums[position]), nums_size);
        for (int nextPosition = position + 1; nextPosition <= furthestJump; nextPosition++)
        {
            if (canJumpFromPosition(nextPosition, nums)) 
            {
                return true;
            }
        }

        return false;
    }
};