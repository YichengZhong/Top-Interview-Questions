class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
         vector<int>v_out;
         v_out.clear();

         for(int i=0;i<nums.size();++i)
         {
             int index=abs(nums[i])-1;
             nums[index]=-nums[index];

             if(nums[index]>0)
             {
                 v_out.push_back(index+1);
             }
         }


         return v_out;

    }
};