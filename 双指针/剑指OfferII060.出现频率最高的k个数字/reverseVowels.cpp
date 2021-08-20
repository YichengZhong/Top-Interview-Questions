class Solution {
public:
    string reverseVowels(string s) {
        auto isVowel = [vowels = "aeiouAEIOU"s](char ch) {
            return vowels.find(ch) != string::npos;
        };

        //双指针法
        int n = s.size();
        int right = 0, left = n - 1;
        while (right < left) 
        {
            while (right < n && !isVowel(s[right])) 
            {
                ++right;
            }
            while (left > 0 && !isVowel(s[left])) 
            {
                --left;
            }
            if (right < left) 
            {
                swap(s[right], s[left]);
                ++right;
                --left;
            }
        }
        return s;
    }
};