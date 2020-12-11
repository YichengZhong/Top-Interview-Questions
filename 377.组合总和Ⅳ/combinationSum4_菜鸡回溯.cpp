class Solution {
public:
    int count;
    int combinationSum4(vector<int>& nums, int target) {
        count=0;

        helpDFS(nums,0,0,target);

        return count;
    }

    void helpDFS(vector<int>& nums, int index,int sum,int target)
    {
        if(sum==target)
        {
            count++;
        }

        if(sum>target) return;

        for(int i=index;i<nums.size();++i)
        {
            helpDFS(nums,index,sum+nums[i],target);
        }
    }
};