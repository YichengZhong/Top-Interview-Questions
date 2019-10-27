class Solution {
public:
    int sumhalf;
    bool flag;
    bool canPartition(vector<int>& nums) {       
        int sum=0;
        for(int i=0;i<nums.size();++i)
        {
            sum=sum+nums[i];
        }
        
        if(sum%2==1)
            return false;
        
        sumhalf=sum/2;
        flag=false;
        //回溯排序
        sort(nums.begin(), nums.end());
        
        dfs(0,0,nums);
        
        return flag;
    }
    
    void dfs(int index, int sum,vector<int> vc) 
    {
        if (sum == sumhalf) 
        {
           flag=true;
        }
        for (int i = index; i < vc.size(); i++)
        {
            sum += vc[i];
            dfs(i + 1,sum,vc);
            sum -= vc[i];
        }
    }
};