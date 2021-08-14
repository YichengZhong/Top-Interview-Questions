class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()<=0) return 0;

        unordered_set<char>lookup;
        int maxStr = 0;

        int left=0,right=0;

        while(right<s.size())
        {
            while(lookup.find(s[right]) != lookup.end())
            {
                lookup.erase(s[left]);
                left++;
            }

            lookup.insert(s[right]);
            maxStr = max(maxStr,right-left+1);
            right++;
        }

        return maxStr;
    }
};