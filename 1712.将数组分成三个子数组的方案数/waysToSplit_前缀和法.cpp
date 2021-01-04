class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        if(nums.size()<3) return 0;
    
        //前缀和的算法
        vector<int>prex_sum(nums.size(),0);
        const int MOD = 1e9 + 7;

        for(int i=0;i<nums.size();++i)
        {
            if(0==i)
            {
                prex_sum[0]=nums[i];
            }
            else
            {
                prex_sum[i]=nums[i]+prex_sum[i-1];
            }
        }

        long long count=0;

        for(int left=0;left<nums.size()-2;++left)
        {
            for(int mid=left+1;mid<nums.size()-1;++mid)
            {
                int left_sum=prex_sum[left];
                int mid_sum=prex_sum[mid]-prex_sum[left];
                int right_sum=prex_sum[prex_sum.size()-1]-prex_sum[mid];

                if(left_sum<=mid_sum && mid_sum<=right_sum)
                {
                    count++;
                }
            }
        }

        return count%MOD;
    }
};