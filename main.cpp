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

unordered_map<char, string> phoneMap{
			{'0', "0000"},
			{'1', "0001"},
			{'2', "0010"},
			{'3', "0011"},
			{'4', "0100"},
			{'5', "0101"},
			{'6', "0110"},
			{'7', "0111"},
			{'8', "1000"},
			{'9', "1001"},
			{'A', "1010"},
			{'B', "1011"},
			{'C', "1100"},
			{'D', "1101"},
			{'E', "1110"},
			{'F', "1111"},
			{'a', "1010"},
			{'b', "1011"},
			{'c', "1100"},
			{'d', "1101"},
			{'e', "1110"},
			{'f', "1111"},
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
	for (int i = 0; i < strhex.size(); ++i)
	{
		if (!isHex(strhex[i]))
		{
			cout << "Fuck" << endl;
			return strhex;
		}
		temp = temp + phoneMap[strhex[i]];
	}
	cout << temp << endl;
	return temp;
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

	return 0;
}