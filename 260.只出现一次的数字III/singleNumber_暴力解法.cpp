class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int> um_count;;
        vector<int>v_out;

        for(int i=0;i<nums.size();++i)
        {
            um_count[nums[i]]++;
        }

        for(auto it=um_count.begin();it!=um_count.end();++it)
        {
            if(it->second==1)
            {
                v_out.push_back(it->first);
            }
        }

        return v_out;
    }
};