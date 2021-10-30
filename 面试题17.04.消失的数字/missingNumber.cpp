class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<int>flagnum(nums.size()+1,1);

        for(int i=0;i<nums.size();++i)
        {
            flagnum[nums[i]]=0;
        }
        for(int i=0;i<flagnum.size();++i)
        {
            if(flagnum[i]==1)
            {
                return i;
            }
        }

        return 0;
    }
};