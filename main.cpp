#include<vector>
#include<iostream>
#include<unordered_map>
#include <minmax.h>
#include<string>
using namespace std;

class Solution {
public:
	int maxAscendingSum(vector<int>& nums) {
		if (nums.size() == 1) return nums[0];

		int maxSum = 0;
		int tempSum = 0;

		for (int i = 0; i < nums.size(); ++i)
		{
			tempSum = nums[i];
			for (int j = i + 1; j < nums.size(); ++j)
			{
				if ((nums[j] - nums[j - 1]) > 0)
				{
					tempSum = tempSum + nums[j];
				}
				else
				{
					maxSum = max(maxSum, tempSum);
					break;
				}
			}
		}

		return maxSum;
	}
};

void test(int *p)
{
	cout << "*p" << *p << endl;
	*p = 100;
	cout << "*p" << *p << endl;
}

enum SupportedFeatureFlgConst
{
	Supp
};

class SupportedFeatures
{
public:
	SupportedFeatures();
	~SupportedFeatures();
	SupportedFeatures(const SupportedFeatures&);
	SupportedFeatures &operator=(const SupportedFeatures&);

	SupportedFeatures &add(size_t feature);
	SupportedFeatures &add(std::initializer_list<size_t> features);

private:
	std::string __feartures;
};

unordered_map<char, int> hex_to_num{
			{'0', 0},
			{'1', 1},
			{'2', 2},
			{'3', 3},
			{'4', 4},
			{'5', 5},
			{'6', 6},
			{'7', 7},
			{'8', 8},
			{'9', 9},
			{'A', 10},
			{'B', 11},
			{'C', 12},
			{'D', 13},
			{'E', 14},
			{'F', 15},
			{'a', 10},
			{'b', 11},
			{'c', 12},
			{'d', 13},
			{'e', 14},
			{'f', 15},
};

unordered_map<int, char> num_to_hex{
			{0, '0'},
			{1, '1'},
			{2, '2'},
			{3, '3'},
			{4, '4'},
			{5, '5'},
			{6, '6'},
			{7, '7'},
			{8, '8'},
			{9, '9'},
			{10, 'A'},
			{11, 'B'},
			{12, 'C'},
			{13, 'D'},
			{14, 'E'},
			{15, 'F'},
};

bool isHex(char chr)
{
	if ((chr >= '0'&&chr <= '9') || (chr >= 'a'&&chr <= 'f') || (chr >= 'A'&&chr <= 'F'))
	{
		return true;
	}

	return false;
}

string string_to_binary(const string &strhex)
{
	string temp = "";
	/*for (int i = 0; i < strhex.size(); ++i)
	{
		if (!isHex(strhex[i]))
		{
			cout << "Fuck" << endl;
			return strhex;
		}
		temp = temp + phoneMap[strhex[i]];
	}
	cout << temp << endl;*/
	return temp;
}

//https://www.cnblogs.com/ct0421/p/3547629.html
string &SetFeature(string &strFeatures, size_t index)
{
	if (index > 4*strFeatures.size()) return strFeatures;

	size_t index_family = 0;
	size_t index_in_family = 0;
	index_family = (index-1) / 4;
	index_in_family = (index-1) % 4;

	size_t strFeatures_feature_index = hex_to_num[strFeatures[strFeatures.size()-1-index_family]];
	cout << "strFeatures[strFeatures.size()-1-index_family]=" << strFeatures[strFeatures.size() - 1 - index_family] << endl;

	cout << "strFeatures_feature_index 1:" << strFeatures_feature_index << endl;
	strFeatures_feature_index |= (1 << index_in_family);
	cout << "strFeatures_feature_index 2:" << strFeatures_feature_index << endl;
	strFeatures[strFeatures.size() - 1 - index_family] = num_to_hex[strFeatures_feature_index];

	return strFeatures;
}

string &ResetFeature(string &strFeatures, size_t index)
{
	if (index > 4 * strFeatures.size()) return strFeatures;

	size_t index_family = 0;
	size_t index_in_family = 0;
	index_family = (index - 1) / 4;
	index_in_family = (index - 1) % 4;

	size_t strFeatures_feature_index = hex_to_num[strFeatures[strFeatures.size() - 1 - index_family]];
	cout << "strFeatures[strFeatures.size()-1-index_family]=" << strFeatures[strFeatures.size() - 1 - index_family] << endl;

	cout << "strFeatures_feature_index 1:" << strFeatures_feature_index << endl;
	strFeatures_feature_index &= ~(1 << index_in_family);
	cout << "strFeatures_feature_index 2:" << strFeatures_feature_index << endl;
	strFeatures[strFeatures.size() - 1 - index_family] = num_to_hex[strFeatures_feature_index];

	return strFeatures;
}

bool searchFeature(string &strFeatures, size_t index)
{
	if (index > 4 * strFeatures.size()) return false;
	size_t index_family = 0;
	size_t index_in_family = 0;
	index_family = (index - 1) / 4;
	index_in_family = (index - 1) % 4;

	size_t strFeatures_feature_index = hex_to_num[strFeatures[strFeatures.size() - 1 - index_family]];

	if (strFeatures_feature_index >> (index_in_family) & 1)   //判断第index位是否为一
	{
		cout <<"第"<<index <<"位为1" << endl;
		return true;

	}
	return false;
}

int main()
{
	string str; // string to convert
	size_t pos; // Hold position of stopping character

	//Convert string to double
	str = "-342.57is a number";
	cout << "The string is " << str << endl;
	double d = stod(str, &pos);
	cout << "The converted double is " << d << endl;
	cout << "The stopping character is " << str[pos] << " at position " << pos << endl;
	// Convert string to int (default to decimal)
	str = "-342.57is a number";
	cout << "\nThe string is " << str << endl;
	int i = stoi(str, &pos);
	cout << "The converted integer is " << i << endl;
	cout << "The stopping character is " << str[pos] << " at position " << pos << endl;
	// Convert string to int (base is binary)
	str = "01110binary number";
	cout << "\nThe string is " << str << endl;
	i = stoi(str, &pos, 2);
	cout << "The converted binary integer is " << i << endl;
	cout << "The stopping character is " << str[pos] << " at position " << pos << endl;

	string binstr = string_to_binary("80000000");
	cout << "binstr=" << binstr << " binstr.size()="<<binstr.size()<< endl;

	binstr = string_to_binary("80001000");
	cout << "binstr=" << binstr << " binstr.size()=" << binstr.size() << endl;

	binstr = string_to_binary("80001X00");
	cout << "binstr=" << binstr << " binstr.size()=" << binstr.size() << endl;

	int a = 8;
	a |= (1 << 5);
	cout << "a:" << a << endl;

	cout << "=============================================" << endl;

	string test1 = "80001000";
	cout << SetFeature(test1, 100) << endl;
	cout << SetFeature(test1, 1) << endl;

	cout << "=============================================" << endl;

	test1 = "8000100";
	cout << SetFeature(test1, 100) << endl;
	cout << SetFeature(test1, 1) << endl;

	cout << "=============================================" << endl;

	test1 = "80001000";
	cout << SetFeature(test1, 100) << endl;
	cout << SetFeature(test1, 12) << endl;

	cout << "=============================================" << endl;

	test1 = "80001000";
	cout << SetFeature(test1, 100) << endl;
	cout << SetFeature(test1, 21) << endl;

	cout << "=============================================" << endl;

	test1 = "80001000";
	cout << SetFeature(test1, 100) << endl;
	cout << SetFeature(test1, 26) << endl;

	cout << "=============================================" << endl;

	test1 = "80001000";
	cout << ResetFeature(test1, 100) << endl;
	cout << ResetFeature(test1, 32) << endl;

	cout << "=============================================" << endl;

	test1 = "80001000";
	cout << searchFeature(test1, 100) << endl;
	cout << searchFeature(test1, 32) << endl;

	cout << "=============================================" << endl;

	test1 = "80001000";
	cout << searchFeature(test1, 100) << endl;
	cout << searchFeature(test1, 12) << endl;

	return 0;
}