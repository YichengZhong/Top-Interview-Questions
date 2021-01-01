class Solution {
public:
    bool halvesAreAlike(string s) {
        string s1 = "", s2 = "";
        int len = s.length();
        int left = 0, right = len - 1;
        int mid = left + (right - left) / 2; // 这种写法等同于 (left + right) / 2
        
        s1 = s.substr(left, mid + 1);
        s2 = s.substr(mid + 1, len - mid - 1);
        
        return countVowels(s1) == countVowels(s2);
    }
    
    int countVowels(string& str) {
        int count = 0;
        
        for (char c : str) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
                count++;
            }
        }
        
        return count;

    }
};