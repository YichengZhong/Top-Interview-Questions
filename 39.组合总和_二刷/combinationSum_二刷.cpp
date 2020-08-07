class Solution {
public:
    vector<vector<int>> v_out;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        v_out.clear();
        vector<int>v_tmp;
        sort(candidates.begin(),candidates.end());
        help(candidates,v_tmp,0,target,0);
        return v_out;
    }

    void help(vector<int> candidates,vector<int> v_tmp,int sum,int target,int index)
    {
        if(sum==target)
        {
            v_out.push_back(v_tmp);
        }
        else if(sum>target)
        {
            return ;
        }
        else if(sum<target)
        {
            for(int i=index;i<candidates.size();++i)
            {
                v_tmp.push_back(candidates[i]);
                help(candidates,v_tmp,sum+candidates[i],target,i);
                v_tmp.pop_back();
            }
        }
    }
};