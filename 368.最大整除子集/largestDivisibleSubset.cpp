class Solution {
public:
    //菜鸡回溯
    vector<int> outVector;
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        outVector.clear();

        helpDFS(nums,0,{});

        return outVector;
    }

    void helpDFS(vector<int>& nums,int index , vector<int> temp)
    {
        if(temp.size()>=outVector.size()) outVector=temp;
        if(index>nums.size()) return;

        for(int i=index;i<nums.size();++i)
        {
            if(isInVector(temp,nums[i]))
            {
                temp.push_back(nums[i]);
                helpDFS(nums,i+1,temp);
                temp.pop_back();
            }
        }
    }

    bool isInVector(vector<int> temp,int num)
    {
        for(int i=0;i<temp.size();++i)
        {
            if(temp[i]%num!=0 && num%temp[i]!=0) return false;
        }

        return true;
    }
};