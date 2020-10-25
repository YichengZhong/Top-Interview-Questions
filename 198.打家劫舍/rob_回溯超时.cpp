class Solution {
public:
	int robVaule;
	int rob(vector<int>& nums) {
		robVaule = 0;

		helpDFS(nums, 0, 0);

		return robVaule;
	}

	void helpDFS(vector<int>& nums, int index, int sum)
	{
		if (index >= (nums.size() - 1))
		{
			robVaule = max(robVaule, sum);
		}

		for (int i = index; i < nums.size(); ++i)
		{
			helpDFS(nums, i + 2, sum + nums[i]);
		}
	}
};