class Solution {
public:
    void sortColors(vector<int>& nums) {
         int temp[3]={0};
        
        for(int i=0;i<nums.size();++i)
        {
            temp[nums[i]]++;
        }
        
        vector<int> nums_2;
        for(int i=0;i<3;++i)
        {
            for(int j=0;j<temp[i];++j)
            {
                nums_2.push_back(i);
            }
        }
        
        nums=nums_2;
        
    }
};