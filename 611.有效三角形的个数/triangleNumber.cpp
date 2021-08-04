class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if(nums.size()<3) return 0;

        sort(nums.begin(),nums.end());

        int count=0;
        for(int i=0;i<nums.size();++i)
        {
            for(int j=i+1;j<nums.size();++j)
            {
                //二分法找到第一个不符合的k
                int left=j+1,right=nums.size()-1,mid=j,k=j;
                while(left<=right)
                {
                    mid=(right+left)/2;

                    if(nums[mid] < nums[i] + nums[j])
                    {
                        k=mid;
                        left=mid+1;
                    }
                    else
                    {
                        right=mid-1;
                    }
                }

                count=count+(k-j);
            }
        }

        return count;
    }
};