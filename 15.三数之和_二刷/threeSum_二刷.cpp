class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>v_out;
        v_out.clear();

        if(nums.size()<3)
        {
            return v_out;
        }

        sort(nums.begin(),nums.end());

        for(int i=0;i<=nums.size()-3;++i)
        {
            if(nums[i]>0)
            {
                break;
            }

            if(i > 0 && nums[i] == nums[i-1])
            {
                continue; // 去重
            }

            int left=i+1;
            int right=nums.size()-1;

            while(left<right)
            {
                int temp=nums[i]+nums[left]+nums[right];

                if(temp==0)
                {
                    vector<int>v_tmp;
                    v_tmp.push_back(nums[i]);
                    v_tmp.push_back(nums[left]);
                    v_tmp.push_back(nums[right]);
                    v_out.push_back(v_tmp);

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
                else if(temp<0)
                {
                    left++;
                }
                else if(temp>0)
                {
                    right--;
                }
            }
        }

        return v_out;
    }
};