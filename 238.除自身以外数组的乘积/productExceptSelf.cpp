class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> v1(n,1),v2(n,1);
        
        for(int i=1;i<n;i++)
        {//求左积
            v1[i]=v1[i-1]*nums[i-1];
        }
        
        for(int i=n-2;i>=0;i--)
        {//求右积
            v2[i]=v2[i+1]*nums[i+1];
        }
        
        for(int i=0;i<n;i++)
        {//左积*右积
            v1[i]*=v2[i];
        }
        
        return v1;
        
    }
};