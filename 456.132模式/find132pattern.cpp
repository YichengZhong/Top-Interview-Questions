class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        vector<int>min_right;
        vector<int>min_left;

        for(int i=0;i<nums.size();++i)
        {
            if(min_left.size()==0)
            {
                min_left.push_back(nums[i]);
            }
            else
            {
                if(nums[i]>=min_left.back())
                {
                    int temp=min_left.back();
                    min_left.push_back(temp);
                }
                else
                {
                    min_left.push_back(nums[i]);
                }
            }
        }

        for(int i=nums.size()-1;i>=0;--i)
        {
            if(min_right.size()==0)
            {
                min_right.push_back(nums[i]);
            }
            else
            {
                if(nums[i]<=min_right.back())
                {
                    int temp=min_right.back();
                    min_right.push_back(temp);
                }
                else
                {
                    min_right.push_back(nums[i]);
                }
            }
        }

        reverse(min_right.begin(),min_right.end());

        for(int i=0;i<nums.size();++i)
        {
            if(nums[i]>min_left[i] && nums[i]>min_right[i] && min_left[i]<min_right[i])
            {
                return true;
            }
        }

        return false;

    }
};