class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,vector<int>>numsCount;

        for(int i=0;i<nums.size();++i)
        {
            numsCount[nums[i]].push_back(i);
        }

        int maxNumCounts=1;
        int maxNumLen=1;
        for(auto iter=numsCount.begin();iter!=numsCount.end();++iter)
        {
            if(maxNumCounts<(iter->second).size())
            {
                maxNumCounts=(iter->second).size();
                maxNumLen=(iter->second)[maxNumCounts-1]-(iter->second)[0]+1;
            }
            if(maxNumCounts==(iter->second).size())
            {
                maxNumLen=min(maxNumLen,(iter->second)[maxNumCounts-1]-(iter->second)[0]+1);
            }
        }

        return maxNumLen;
    }
};