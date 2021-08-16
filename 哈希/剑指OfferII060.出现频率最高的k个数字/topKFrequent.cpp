class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>m_count;

        for(int i=0;i<nums.size();++i)
        {
            m_count[nums[i]]++;
        }

        vector<int>v_count;
        v_count.clear();
        for(auto it=m_count.begin();it!=m_count.end();++it)
        {
            v_count.push_back(it->second);
        }

        sort(v_count.begin(),v_count.end());
        reverse(v_count.begin(),v_count.end());

        int count=v_count[k-1];
        vector<int>v_out;

        for(auto it=m_count.begin();it!=m_count.end();++it)
        {
            if(it->second>=count)
            {
                v_out.push_back(it->first);
            }
        }

        return v_out;
    }
};