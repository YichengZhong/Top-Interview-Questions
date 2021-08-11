class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size()<3) return {};

        vector<vector<int>>out;

        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size()-2;++i)
        {
            if(nums[i]>0)
            {
                break;
            }

            if(i > 0 && nums[i] == nums[i-1])
            {
                continue; // 去重
            }

            int left=i+1,right=nums.size()-1;

            while(left<right)
            {
                int sum=nums[i]+nums[left]+nums[right];

                if(0==sum)
                {
                    vector<int>temp={nums[i],nums[left],nums[right]};
                    out.push_back(temp);

                    //找到最短距离
                    while(left<right && nums[left]==nums[left+1])
                    {
                        left++;
                    }

                    while(left<right && nums[right]==nums[right-1])
                    {
                        right--;
                    }

                    left++;
                    right--;
                }
                else if(sum>0)
                {
                    right--;
                }
                else
                {
                    left++;
                }
            }
        }

        return out;
    }
};