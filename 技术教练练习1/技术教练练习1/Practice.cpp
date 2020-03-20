#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <math.h>
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

			cout << Expression << endl;
			v_out_string.push_back(Expression);
			//cout << Expression<<"="<< myCalculate.calculate(Expression)<< endl;
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
		//DFS(nums, digit, counter + 1, Expression,"-");
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

	vector<string>v_out_string;
};

void test1()
{
    vector<int>nums;
	nums.clear();


	int digit = 7;

	for (int i = 0; i < 6; ++i)
	{
		nums.push_back(digit);
	}

	Solution mySolution;
	mySolution.v_out_string.clear();
	mySolution.findTargetSumWays(nums);

	Calculate myCalculate;

	for (int i = 0; i < mySolution.v_out_string.size(); ++i)
	{
		cout << mySolution.v_out_string[i] << "=" << myCalculate.calculate(mySolution.v_out_string[i]) << endl;
	}
}

void splitdigit(int i, int v)
{
	int temp = v;

	if (0 == i)
	{
		return;
	}

	while (temp>0)
	{
		int j = (-1);
		while (pow(i, j+1) < temp)
		{
			j++;
		}

		int an = 1;
		if (j > 0)
		{
			an = temp / pow(i, j);
		}
		else
		{
			an = 1;
		}

		cout << "temp=" << temp << " an=" << an << " pow(i, j)=" << pow(i, j) << " j=" << j << endl;
		temp = temp - an * pow(i, j);
		//cout <<"After temp=" << temp << " an=" << an << " pow(i, j)=" << pow(i, j) << " j=" << j << endl;
	}
	return ;
}

void test2()
{
	char mmlInfo[16*1024]="112334";
	char info[] = "asfsf";
	char c_flag[] = "&";
	int mmlInfoLen = strlen(mmlInfo);

	snprintf(&(mmlInfo[mmlInfoLen]), strlen(info), "%s", info);

	cout << "1:" << mmlInfo << endl;

	int mmlInfoLen2 = strlen(mmlInfo);

	snprintf(&(mmlInfo[strlen(mmlInfo)]), strlen(c_flag)+1, "%s", c_flag);
	cout << "2:" << mmlInfo << endl;
}

void test3(char mmlInfo2[])
{
	char mmlInfo[16 * 1024] = "112334";
	char info[] = "asfsf";
	char c_flag[] = "&";

	cout << "1:" << sizeof(mmlInfo2) << endl;
}

int main()
{
	//test1();
	cout <<"============================================================\n" << endl;
	//Calculate myCalculate;
	//cout << "7/7/7/7/7" << "=" << myCalculate.calculate("7/7/7/7/7") << endl;
	test2();
	char mmlInfo2[] = "12414";
	//test3(mmlInfo2);
	//splitdigit(7, 100);
	return 0;
}