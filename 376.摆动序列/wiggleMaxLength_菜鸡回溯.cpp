class Solution {
public:
    //DFS简单背包问题，要不要加入数组
    int maxlen;
    int wiggleMaxLength(vector<int>& nums) {
        maxlen=0;
        vector<int> v_temp;
        v_temp.clear();

        helpDFS(nums,v_temp,0);
        return maxlen;
    }

    void helpDFS(vector<int>& nums,vector<int> v_temp,int index)
    {
        //保证进入v_temp一定是合格的
        if(index>nums.size()) return;
        
        maxlen=maxlen>v_temp.size()?maxlen:v_temp.size();

        for(int i=index;i<nums.size();++i)
        {
            if(v_temp.size()==0)
            {
                v_temp.push_back(nums[i]);
                helpDFS(nums,v_temp,i+1);
                v_temp.pop_back();
            }
            else if(v_temp.size()==1)
            {
                if(v_temp[0]!=nums[index])
                {
                    v_temp.push_back(nums[i]);
                    helpDFS(nums,v_temp,i+1);
                    v_temp.pop_back();
                }
            }
            else
            {
                int FirstIndex=v_temp.size()-2;
                int SecondIndex=v_temp.size()-1;

                if(v_temp[SecondIndex]<v_temp[FirstIndex] && nums[i]>v_temp[SecondIndex])
                {
                    v_temp.push_back(nums[i]);
                    helpDFS(nums,v_temp,i+1);
                    v_temp.pop_back();
                }
                else if(v_temp[SecondIndex]>v_temp[FirstIndex] && nums[i]<v_temp[SecondIndex])
                {
                    v_temp.push_back(nums[i]);
                    helpDFS(nums,v_temp,i+1);
                    v_temp.pop_back();
                }
            }
        }
    }
};