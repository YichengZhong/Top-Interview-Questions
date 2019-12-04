class Solution {
public:
    int firstUniqChar(string s) {
         int i = 0, j = 0;
         int len = s.size();
    int freq[26] = { 0 };
    for (i = 0; i < len; i++) {
        freq[s[i] - 'a']++;
    }
    for (i = 0; i < len; i++) {
        if (freq[s[i] - 'a'] == 1)
            return i;
    }
    return -1;

        
    }
};