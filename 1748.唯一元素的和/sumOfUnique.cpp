class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int,int>numsmap;

        for(int i=0;i<nums.size();++i)
        {
            numsmap[nums[i]]++;
        }

        int sum=0;

        for(auto iter=numsmap.begin();iter!=numsmap.end();++iter)
        {
            if(iter->second==1)
                sum=sum+iter->first;
        }

        return sum;

    }
};