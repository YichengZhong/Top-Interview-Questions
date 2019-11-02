class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max=INT_MIN;
        int imax=1,imin=1;
        
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] < 0)
            { 
              int tmp = imax;
              imax = imin;
              imin = tmp;
            }
            imax =(imax*nums[i])>nums[i]?(imax*nums[i]):nums[i];
            imin =(imin*nums[i])>nums[i]?nums[i]:(imin*nums[i]);
            
            max = max>imax?max:imax;
        }
        return max;
        
    }
};