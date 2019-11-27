class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int>temp;
        
        for(int i=0;i<nums.size();++i)
        {
            if(temp[nums[i]]==0)
            {
                temp[nums[i]]=1;
            }
            else
            {
                temp[nums[i]]++;
            }
        }
        
        for(map<int,int>::iterator it=temp.begin();it!=temp.end();++it)
        {
            if((*it).second>(nums.size()/2))
            {
                return (*it).first;
            }
        }
        
        return 0;
        
    }
};