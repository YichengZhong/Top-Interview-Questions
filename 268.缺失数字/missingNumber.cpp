class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<int>temp;
        
        for(int i=0;i<nums.size()+1;++i)
        {
            temp.push_back(i+1);
        }
        
        for(int i=0;i<nums.size();++i)
        {
            temp[nums[i]]=0;
        }
        
        for(int i=0;i<temp.size();++i)
        {
            if(temp[i]!=0)
            {
                return i;
            }
        }
        
        return 0;
    }
};