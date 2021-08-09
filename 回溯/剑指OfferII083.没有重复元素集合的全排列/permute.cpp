class Solution {
public:
    //全排列题
    vector<vector<int>> out;
    vector<vector<int>> permute(vector<int>& nums) {
        helpDFS(nums,nums,0);
        return out;

    }

    void helpDFS(vector<int>& nums,vector<int>temp,int index)
    {
        if(index==nums.size())
        {
            out.push_back(temp);
            return;
        }

        if(index>=nums.size()) return;

        for(int i=index;i<nums.size();++i)
        {
            swap(temp[i],temp[index]);
            helpDFS(nums,temp,index+1);
            swap(temp[i],temp[index]);
        }
    }

    void swap(int &a,int &b)
    {
        int temp=0;
        temp=a;
        a=b;
        b=temp;
    }
};