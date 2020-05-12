#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <math.h>
#include <algorithm>
#include <unordered_set>
#include <vector>
#include "cJSON.h"
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


class Solution3 {
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

void test12()
{
	char mmlInfo[16*1024]="112334";
	char info[] = "asfsf";
	char c_flag[] = "&";
	int mmlInfoLen = strlen(mmlInfo);

	snprintf(&(mmlInfo[strlen(mmlInfo)]), strlen(info), "%s", info);

	cout << "1:" << mmlInfo << endl;

	int mmlInfoLen2 = strlen(mmlInfo);

	snprintf(&(mmlInfo[strlen(mmlInfo)]), strlen(c_flag)+1, "%s", c_flag);
	cout << "2:" << mmlInfo << endl;
	snprintf(&(mmlInfo[strlen(mmlInfo)]), strlen(info), "%s", info);
	snprintf(&(mmlInfo[strlen(mmlInfo)]), strlen(c_flag) + 1, "%s", c_flag);
	cout << "3:" << mmlInfo << endl;
	snprintf(&(mmlInfo[strlen(mmlInfo)]), strlen(info), "%s", info);
	snprintf(&(mmlInfo[strlen(mmlInfo)]), strlen(c_flag) + 1, "%s", c_flag);
	cout << "4:" << mmlInfo << endl;
}

void test3(char mmlInfo2[])
{
	char mmlInfo[16 * 1024] = "112334";
	char info[] = "asfsf";
	char c_flag[] = "&";

	cout << "1:" << sizeof(mmlInfo2) << endl;
}




class Solution2 {
public:
    bool compare(string a, string b)
	{
		if (atoll((a + b).c_str()) > atoll((b + a).c_str()))
		{
			return true;
		}

		return false;
	}

	string largestNumber(vector<int>& nums) {
		vector<string>str_nums;
		str_nums.clear();

		if (0 == nums.size())
		{
			return "";
		}

		for (int i = 0; i < nums.size(); ++i)
		{
			str_nums.push_back(to_string(nums[i]));

			compare("11", "22");
		}

		sort(str_nums.begin(), str_nums.end());

		//reverse(str_nums.begin(),str_nums.end());

		string str_out = "";

		for (int i = 0; i < str_nums.size(); ++i)
		{
			str_out = str_out + str_nums[i];
		}

		if (atoll(str_out.c_str()) == 0)
		{
			return "0";
		}

		return str_out;

	}
};

#define VALUE_MAX (unsigned int)200

class Solution {
public:
	static int getF(int x)
	{
		if (x == 1)
		{
			return 0;
		}

		if (x & 1)
		{
			return getF(x * 3 + 1) + 1;
		}
		else
		{
			return getF(x / 2) + 1;
		}
	}

	static bool selfcmp(int a, int b)
	{
		if (getF(a) > getF(b))
		{
			return false;
		}
		else if (getF(a) < getF(b))
		{
			return true;
		}
		else
		{
			return a < b;
		}
	}

	int getKth(int lo, int hi, int k) {
		vector<int> nums;
		nums.clear();

		for (int i = lo; i <= hi; ++i)
		{
			nums.push_back(i);
		}

		sort(nums.begin(), nums.end(), selfcmp);

		return nums[k - 1];

	}
};
int abc()
{
	//test1();
	cout <<"============================================================\n" << endl;
	//Calculate myCalculate;
	//cout << "7/7/7/7/7" << "=" << myCalculate.calculate("7/7/7/7/7") << endl;
	//test2();
	char mmlInfo2[] = "12414";
	//test3(mmlInfo2);
	//splitdigit(7, 100);

	Solution mySolution;
	vector<int>cardPoints = {4,2,2,2,4,4,2,2};
	int out = 0;
	out=mySolution.getKth(12, 15,  2);
	cout << out << endl;

	return 0;
}