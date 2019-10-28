class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // 用数组记录答案
    vector<int> res;
    int left = 0, right = 0;
    unordered_map<char, int> needs;
    unordered_map<char, int> window;
    for (char c : p) needs[c]++;
    int match = 0;
    
    while (right < s.size()) 
    {
        char c1 = s[right];
        if (needs.count(c1)) 
        {
            window[c1]++;
            if (window[c1] == needs[c1])
                match++;
        }
        
        right++;

        while (match == needs.size())
        {
            // 如果 window 的大小合适
            // 就把起始索引 left 加入结果
            if (right - left == p.size())
            {
                res.push_back(left);
            }
            char c2 = s[left];
            if (needs.count(c2))
            {
                window[c2]--;
                if (window[c2] < needs[c2])
                    match--;
            }
            left++;
        }
    }
    
        return res;
        
    }
};