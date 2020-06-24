class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int out=nums.size()+2;

        int left=0,right=0;
        int sum=0;
        while(right<nums.size())
        {
            int temp=nums[right];

            sum=sum+temp;

            while(sum>=s)
            {
                int temp_left=nums[left];
                sum=sum-temp_left;
                out=min(out,right-left+1);
                left++;
            }

            right++;
        }

        if(out>nums.size())
        {
            return 0;
        }

        return out;
    }
};