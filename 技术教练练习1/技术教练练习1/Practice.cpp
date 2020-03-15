#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	void DFS(vector<int>& nums, int digit,int counter,string Expression,string sign)
	{
		if (counter == nums.size())
		{
			cout << Expression << endl;
			return;
		}
		//counter = counter + 1;
		Expression = Expression + sign + to_string(digit);
		DFS(nums, digit,counter + 1, Expression,"+");
		DFS(nums, digit,counter + 1, Expression, "-");
		DFS(nums, digit,counter + 1, Expression, "*");
		DFS(nums, digit,counter + 1, Expression, "/");
	}

	void DFS(vector<int>& nums, int digit,int counter, string Expression)
	{
		DFS(nums, digit, counter + 1, Expression,"+");
		DFS(nums, digit, counter + 1, Expression,"-");
		DFS(nums, digit, counter + 1, Expression,"*");
		DFS(nums, digit, counter + 1, Expression,"/");
	}

	int findTargetSumWays(vector<int>& nums)
	{
		int count = 0;
		int digit = 7;
		string Expression="";

		DFS(nums, digit, 0, Expression);
		return count;
	}

};

int main()
{
	vector<int>nums;
	nums.clear();

	int digit = 7;

	for (int i = 0; i < 4; ++i)
	{
		nums.push_back(digit);
	}

	Solution mySolution;
	mySolution.findTargetSumWays(nums);

	return 0;
}