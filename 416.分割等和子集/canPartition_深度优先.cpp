class Solution {
public:
    void DFS(vector<int>& nums, int S, int& count, int counter, int sum)
    {
        if(counter>=nums.size())
        {
            return;
        }
        if(sum == S)
        {
            ++ count;
            return;
        }

        DFS(nums, S, count, counter + 1, sum + nums[counter]);
        DFS(nums, S, count, counter + 1, sum);
    }
    
    bool canPartition(vector<int>& nums) 
    {
        int sum=0;
        int count=0;
        for(int i=0;i<nums.size();++i)
        {
            sum=sum+nums[i];
        }
        
        if(sum%2==1)
            return false;
        
        DFS(nums,sum/2,count,0,0);
        
        if(count>0)
        {
            return true;
        }
        
        return false;
        
    }
};