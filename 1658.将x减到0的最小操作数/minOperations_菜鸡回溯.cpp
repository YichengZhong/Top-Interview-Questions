class Solution {
public:
    int minValue;
    int flag;
    int minOperations(vector<int>& nums, int x) {
        minValue=INT_MAX;
        flag=0;
        helpDFS(nums,x,0,0);
        if(flag==0) return -1;
        return minValue;
    }

    void helpDFS(vector<int> &nums,int x,int sum,int count)
    {
        if(sum==x)
        {
            flag=1;
            minValue=min(minValue,count);
            return ;
        }

        if(nums.size()<=0)
        {
            return ;
        }

        //从尾巴
        int end=nums[nums.size()-1];
        if(end>x || (sum+end) >x )
        {
            return;
        }

        nums.pop_back();
        helpDFS(nums,x,sum+end,count+1);
        nums.push_back(end);

        //从开头
        int start=nums[0];
        if(start>x || (sum+start) >x ) 
        {
            return;
        }

        auto k = nums.begin();
        nums.erase(k);
        helpDFS(nums,x,sum+start,count+1);
        nums.insert(nums.begin(),start);
    }
};