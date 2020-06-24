class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int index = 0;
        vector<int>result(2*n,0);
        for (int i = 0; i < n; i++)
         {
            result[index++] = nums[i];
            result[index++] = nums[n+i];
        }
        return result;
    }
};