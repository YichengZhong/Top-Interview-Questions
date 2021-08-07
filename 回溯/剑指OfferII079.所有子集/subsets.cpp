class Solution {
public:
    vector<vector<int>> out;

    vector<vector<int>> subsets(vector<int>& nums) {
        helpDFS(nums,0,{});
        return out;
    }

    void helpDFS(vector<int>& nums,int index,vector<int>temp)
    {
        if(index>nums.size()) return ;
        
        if(temp.size()<=nums.size())
        {
            out.push_back(temp);
        }

        for(int i=index;i<nums.size();++i)
        {
            temp.push_back(nums[i]);
            helpDFS(nums,i+1,temp);
            temp.pop_back();
        }
    }
};