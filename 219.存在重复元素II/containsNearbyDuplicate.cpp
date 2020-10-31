class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,vector<int>>m_map;

        for(int i=0;i<nums.size();++i)
        {
            m_map[nums[i]].push_back(i);
        }

        for(auto it=m_map.begin();it!=m_map.end();++it)
        {
            int count=(it->second).size();
            if(count>=2)
            {
                for(int i=0;i<count-1;++i)
                {
                    if(((it->second)[i+1]-(it->second)[i])<=k)
                    {
                        return true;
                    }
                }
            }
        }

        return false;

    }
};