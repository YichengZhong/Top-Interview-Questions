#include <vector>
#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Calculate {
public:
	int calculate(string s) {
		stack<int> num;
		stack<char> str;
		for (int i = 0; i < s.size(); ++i)
		{
			if (' ' == s[i]) continue;
			if (s[i] - '0' <= 9 && s[i] - '0' >= 0) //用于处理数字
			{
				int temp = s[i] - '0';
				int j = i + 1;
				while (j < s.size() && s[j] - '0' <= 9 && s[j] - '0' >= 0)//因为可能出现高位数字，不单单是0到9，还有可能是成百上千
				{
					temp = temp * 10 + (s[j] - '0');
					j++;
				}
				i = j - 1;
				num.push(temp);
			}
			else //剩下的只有可能是运算符
			{
				if (str.empty())
				{
					str.push(s[i]);
				}
				else //若是存运算符的栈非空，那么就需要和之前存入的运算符比较优先级
				{
					//当前的运算符优先级高，继续压入
					char pre = str.top();
					if (('+' == pre || '-' == pre) && ('*' == s[i] || '/' == s[i]))
					{
						str.push(s[i]);
					}
					else   //和先前的运算符平级或者之前的运算符优先级高，取出运算
					{
						str.pop();
						int num_1 = num.top();
						num.pop();
						int num_2 = num.top();
						num.pop();
						num.push(fun(num_1, num_2, pre));
						//运算之后，仍然会存在平级，即同为加减级，再运算一次
						if (!str.empty() && ('+' == s[i] || '-' == s[i]))
						{
							char sign = str.top();
							str.pop();
							int num_1 = num.top();
							num.pop();
							int num_2 = num.top();
							num.pop();
							num.push(fun(num_1, num_2, sign));
						}
						str.push(s[i]);
					}

				}
			}
		}
		while (!str.empty())
		{
			char sign = str.top();
			str.pop();
			int num_1 = num.top();
			num.pop();
			int num_2 = num.top();
			num.pop();
			num.push(fun(num_1, num_2, sign));
		}

		return num.top();

	}

	int fun(int num_1, int num_2, char str) //用于计算
	{
		if ('*' == str) 
			return num_1 * num_2;
		else if ('/' == str)
			return num_2 / num_1;
		else if ('+' == str) 
			return num_1 + num_2;
		else  
			return num_2 - num_1;
	}
};


class Solution {
public:
	void DFS(vector<int>& nums, int digit,int counter,string Expression,string sign)
	{
		if (counter == nums.size())
		{
			Calculate myCalculate;

			if (Expression[0] == '+')
			{
				Expression = Expression.substr(1);
			}


			cout << Expression<<"="<< myCalculate.calculate(Expression)<< endl;
			return;
		}
		//counter = counter + 1;
		Expression = Expression + sign + to_string(digit);
		DFS(nums, digit,counter + 1, Expression,"+");
		DFS(nums, digit,counter + 1, Expression,"-");
		DFS(nums, digit,counter + 1, Expression,"*");
		DFS(nums, digit,counter + 1, Expression,"/");
	}

	void DFS(vector<int>& nums, int digit,int counter, string Expression)
	{
		DFS(nums, digit, counter + 1, Expression,"+");
		DFS(nums, digit, counter + 1, Expression,"-");
		//DFS(nums, digit, counter + 1, Expression,"*");
		//DFS(nums, digit, counter + 1, Expression,"/");
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

void test1()
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
}

int main()
{
	test1();
	cout <<"============================================================\n" << endl;
	Calculate myCalculate;
	cout << "7/7*7" << "=" << myCalculate.calculate("7/7*7") << endl;
	return 0;
}