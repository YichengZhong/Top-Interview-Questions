class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());

        int out=0;
                        
        if(nums.size()<3)
            return out;

        out=nums[0]+nums[1]+nums[2];
        
        for(int i=0;i<nums.size();++i)
        {            
            int L=i+1;
            int R=nums.size()-1;
            
            while(L<R)
            {
                int sum = nums[i] + nums[L] + nums[R];
                if(fabs(out-target)>fabs(sum-target))
                {
                    out=  sum;                  
                }
                else if (sum<target)
                {
                    L++;
                }
                else if (sum >target)
                {
                    R--;
                }
                else
                {
                    return out;
                }
            }
            
        }
        
        return out;
        
    }
};