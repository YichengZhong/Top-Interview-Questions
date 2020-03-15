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
			if (s[i] - '0' <= 9 && s[i] - '0' >= 0) //���ڴ�������
			{
				int temp = s[i] - '0';
				int j = i + 1;
				while (j < s.size() && s[j] - '0' <= 9 && s[j] - '0' >= 0)//��Ϊ���ܳ��ָ�λ���֣���������0��9�����п����ǳɰ���ǧ
				{
					temp = temp * 10 + (s[j] - '0');
					j++;
				}
				i = j - 1;
				num.push(temp);
			}
			else //ʣ�µ�ֻ�п����������
			{
				if (str.empty())
				{
					str.push(s[i]);
				}
				else //���Ǵ��������ջ�ǿգ���ô����Ҫ��֮ǰ�����������Ƚ����ȼ�
				{
					//��ǰ����������ȼ��ߣ�����ѹ��
					char pre = str.top();
					if (('+' == pre || '-' == pre) && ('*' == s[i] || '/' == s[i]))
					{
						str.push(s[i]);
					}
					else   //����ǰ�������ƽ������֮ǰ����������ȼ��ߣ�ȡ������
					{
						str.pop();
						int num_1 = num.top();
						num.pop();
						int num_2 = num.top();
						num.pop();
						num.push(fun(num_1, num_2, pre));
						//����֮����Ȼ�����ƽ������ͬΪ�Ӽ�����������һ��
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

	int fun(int num_1, int num_2, char str) //���ڼ���
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