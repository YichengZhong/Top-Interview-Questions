class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if(nums.size()<=1)
        {
            return ;
        }

        sort(nums.begin(),nums.end());

        for(int i=1;i<nums.size()-1;i=i+2)
        {
            int temp=nums[i];
            nums[i]=nums[i+1];
            nums[i+1]=temp;
        }

        return ;
        
    }
};