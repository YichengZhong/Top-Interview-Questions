class Solution {
public:
    vector<vector<int>> v_v_out;
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        v_v_out.clear();
        vector<int>v_temp;
        help(nums,v_temp,0);

        set<vector<int>>s(v_v_out.begin(), v_v_out.end());
        v_v_out.assign(s.begin(), s.end());

        return v_v_out;
    }

    void help(vector<int>& nums,vector<int>v_temp,int index)
    {
        if(v_temp.size()>1)
        {
            v_v_out.push_back(v_temp);
        }
        
        for(int i=index;i<nums.size();++i)
        {
            if(v_temp.size()<1)
            {
                v_temp.push_back(nums[i]);
                help(nums,v_temp,i+1);
                v_temp.pop_back();
            }
            else if(v_temp[v_temp.size()-1]<=nums[i])
            {
                v_temp.push_back(nums[i]);
                help(nums,v_temp,i+1);
                v_temp.pop_back();
            }
        }
    }
};