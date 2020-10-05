class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>v_out;
        v_out.clear();

        if(nums.size()<4)
        {
            return v_out;
        }

        sort(nums.begin(),nums.end());

        for(int i=0;i<=nums.size()-4;++i)
        {
            if(nums[i]>target)
            {
                break;
            }

            if(i > 0 && nums[i] == nums[i-1])
            {
                continue; // 去重
            }

            for(int k=i+1;k<=nums.size()-3;++k)
            {
                if(k>1 && nums[k]==nums[k-1])
                    continue;

                int left=k+1;
                int right=nums.size()-1;

                while(left<right)
                {
                    int temp=nums[i]+nums[k]+nums[left]+nums[right];

                    if(temp==target)
                    {
                        vector<int>v_tmp;
                        v_tmp.push_back(nums[i]);
                        v_tmp.push_back(nums[k]);
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
                    else if(temp<target)
                    {
                        left++;
                    }
                    else if(temp>target)
                    {
                        right--;
                    }
                }

                
            }
        }

        return v_out;
    }
};