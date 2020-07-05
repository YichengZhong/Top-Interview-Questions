#include <iostream>
#include <string>
#include <vector>
using namespace std;

int findEnd(vector<int> &nums, int begin) {
    for (size_t i = begin; i < nums.size() - 1; ++i) {
        if (nums[i] + 1 != nums[i + 1]) {
            return i;
        }
    }
    return nums.size() - 1;
}

class Solution {
public:
    vector<string> summaryRanges(vector<int> &nums) {
        vector<string> answer;
        int begin = 0;
        while (begin < nums.size()) {
            int end = findEnd(nums, begin);
            if (begin == end) {
                string tmp = to_string(nums[begin]);
                answer.push_back(tmp);
            } else {
                string tmp =
                    to_string(nums[begin]) + "->" + to_string(nums[end]);
                answer.push_back(tmp);
            }
            begin = end + 1;
        }
        return answer;
    }
};