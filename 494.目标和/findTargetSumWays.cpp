class Solution {
public:
    void DFS(vector<int>& nums, int S, int& count, int counter, int sum)
    {
        if(counter == nums.size())
        {
            if(sum == S)
                ++ count;
            return;
        }
        //counter = counter + 1;
        DFS(nums, S, count, counter + 1, sum + nums[counter]);
        DFS(nums, S, count, counter + 1, sum -  nums[counter]);
    }
    int findTargetSumWays(vector<int>& nums, int S) 
    {
        int count = 0;
        int sum = 0;
        DFS(nums, S, count, 0, sum);
        return count;
    }

};