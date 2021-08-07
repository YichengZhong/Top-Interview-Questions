class Solution {
public:
    vector<vector<int>>out;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        helpDFS(candidates,target,0,{},0);

        return out;

    }

    void helpDFS(vector<int>& candidates, int target,int sum,vector<int>temp,int index)
    {
        if(index>candidates.size()) return ;

        if(sum==target)
        {
            out.push_back(temp);
            return;
        }

        if(sum>target) return;

        for(int i=index;i<candidates.size();++i)
        {
            temp.push_back(candidates[i]);
            helpDFS(candidates,target,sum+candidates[i],temp,i);
            temp.pop_back();
        }
    }
};