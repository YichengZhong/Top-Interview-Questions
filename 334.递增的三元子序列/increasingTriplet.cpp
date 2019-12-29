class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        long n1 = INT_MAX ;
        long n2 = INT_MAX ;
        long n3 = INT_MAX ;
        for (int i=0;i<nums.size();++i)
         {
            if (nums[i] < n1) 
            {
                n1 = nums[i];
            }
            else if (nums[i] != n1 && nums[i] < n2)
            {
                n2 = nums[i];
            } 
            else if (nums[i] != n1 && nums[i] != n2 && nums[i] < n3) 
            {
                n3 = nums[i];
            }
            if (n1 < n2 && n2 < n3 && n3 < INT_MAX ) 
            {
                return true;
            }
        }
        return false;
    }
};