class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int>nums_conut=nums;
        vector<int>count;
        count.clear();

        for(int i=0;i<nums.size();++i)
        {
            nums_conut[nums[i]-1]=0;
        }

        for(int i=0;i<nums_conut.size();++i)
        {
            if(nums_conut[i]!=0)
                count.push_back(i+1);
        }

        return count;

    }
};