class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int out=1;
        int sum=out;

        for(int i=0;i<nums.size();++i)
        {
            sum=sum+nums[i];

            if(sum<1)
            {
                out=out+(1-sum);
                sum=1;
            }
        }

        return out;
    }
};