class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        map<int,int>m_sumi;
        vector<int> v_Sum;

        for(int i=0;i<nums.size();++i)
        {
            if(i==0)
            {
                m_sumi[0]=nums[i];
                v_Sum.push_back(nums[i]);
                continue;
            }
            else
            {
                m_sumi[i]=m_sumi[i-1]+nums[i];
                v_Sum.push_back(m_sumi[i]);
            }
        }

        return v_Sum;

    }
};