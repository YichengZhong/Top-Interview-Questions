class Solution {
public:
    int flag;
    bool reorderedPowerOf2(int n) {
        string nums = to_string(n);
        flag=0;
        helpDFS(nums,0);

        return flag==1;
    }

    void helpDFS(string &nums,int index)
    {        
        if(flag==1 || nums[0]=='0')
            return;

        int temp=atoi(nums.c_str());
        int x=temp&(temp-1);

        if(x==0)
        {
            flag=1;
            return;
        }

        if(index>=nums.size())
            return ;
        
        for(int i=index;i<nums.size();++i)
        {
            swap(nums[i],nums[index]);
            helpDFS(nums,index+1);
            swap(nums[i],nums[index]);
        }
    }
};