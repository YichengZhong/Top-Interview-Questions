class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        //滑动窗口
        int left_index = 0, right_index = 0;
        unordered_map<char, int> window;
        int count = 0;
        int maxLen = 0;

        if (k >= s.size()) return s.size();

        while (right_index < s.size())
        {
            window[s[right_index]]++;
            while (window.size() > k)
            {
                window[s[left_index]]--;
                if (window[s[left_index]] == 0) 
                {
                    window.erase(s[left_index]);
                }
                left_index++;
            }

            maxLen = max(maxLen, right_index - left_index + 1);
            right_index++;
        }

        return maxLen;
    }
};
