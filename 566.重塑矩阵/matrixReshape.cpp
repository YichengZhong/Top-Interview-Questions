class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int rows = nums.size(), cols = nums[0].size();
        if (rows * cols != r * c) return nums;

        vector<vector<int>> res;
        for (int row = 0; row < r; ++row)
        {
            vector<int> temp;
            res.push_back(temp);
        }

        for (int i = 0; i < r * c; ++i) 
        {
            int row = i / cols;
            int col = i % cols;
            res[i/c].push_back(nums[row][col]);
        }
        return res;
    }
};