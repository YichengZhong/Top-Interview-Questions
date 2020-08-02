class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
                
        vector<vector<int>>v_out;
        v_out.clear();
        
        if(nums.size()<3)
            return v_out;
        
        for(int i=0;i<nums.size();++i)
        {            
            int L=i+1;
            int R=nums.size()-1;
            
            if(nums[i] > 0) 
                break; // 如果当前数字大于0，则三数之和一定大于0，所以结束循环
            if(i > 0 && nums[i] == nums[i-1])
                continue; // 去重
            
            while(L<R)
            {
                int sum = nums[i] + nums[L] + nums[R];
                if(sum == 0)
                {
                    vector<int>v_temp;
                    v_temp.clear();
                    v_temp.push_back(nums[i]);
                    v_temp.push_back(nums[L]);
                    v_temp.push_back(nums[R]);
                    v_out.push_back(v_temp);
                    
                    while (L<R && nums[L] == nums[L+1])
                        L++; // 去重
                    while (L<R && nums[R] == nums[R-1]) 
                        R--; // 去重
                    L++;
                    R--;
                }
                else if (sum < 0)
                    L++;
                else if (sum > 0)
                    R--;
            }
            
        }
        
        return v_out;
        
    }
};