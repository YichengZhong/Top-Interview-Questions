class Solution {
public:
    void nextPermutation(vector<int>& nums) {

       if(nums.size()<=1)//为空或只有一个值，直接返回
       {
           return;
       }

       int i=nums.size()-1;
       int flag=0;

       for(;i>=1;--i)
       {
           if(nums[i]>nums[i-1])
           {
               flag=1;
               break;
           }
       }

       if(0==flag)
       {
           reverse(nums.begin(),nums.end());
           return ;
       }

       int j=nums.size()-1;
       for(;j>=0;--j)
       {
           if(nums[j]>nums[i-1])
           {
               int temp=nums[i-1];
               nums[i-1]=nums[j];
               nums[j]=temp;
               break;
           }
       }

       sort(nums.begin()+i,nums.end());
       return ;
    }
};