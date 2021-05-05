class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int out=INT_MAX;
        for(int i=0;i<nums.size();++i)
        {
            if(nums[i]==target)
            {
                out=min(out,abs(i-start));
            }
        }

        return out;

    }
};