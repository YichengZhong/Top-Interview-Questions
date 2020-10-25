class Solution {
public:
    int robVaule;
    int rob(vector<int>& nums) {
        robVaule=0;

        helpDFS(nums,0,0);

        return robVaule;
    }

    void helpDFS(vector<int>& nums,int index,int sum)
    {
        if(index >= nums.size())
        {
            robVaule=max(robVaule,sum);
            return;
        }

        helpDFS(nums,index+2,sum+nums[index]);
        helpDFS(nums,index+1,sum);
    }
};