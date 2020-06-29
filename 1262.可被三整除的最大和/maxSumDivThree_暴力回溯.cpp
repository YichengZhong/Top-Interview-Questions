class Solution {
public:
    int maxSum;
    int maxSumDivThree(vector<int>& nums) {
        maxSum=0;
        vector<int> vc;
        sort(nums.begin(),nums.end());
        dfs(0,nums,vc);

        return maxSum;
    }

    void dfs(int index,vector<int>nums, vector<int> vc) 
    {
        if (vc.size() <= nums.size()) 
        {
            int temp=accumulate(vc.begin(),vc.end(),0);

            if(temp%3==0 && maxSum<temp)
            {
                maxSum=max(maxSum,temp);
            }
        }
        for (int i = index; i < nums.size(); i++)
        {
            vc.push_back(nums[i]);
            dfs(i + 1,nums,vc);
            vc.pop_back();
        }
    }


};