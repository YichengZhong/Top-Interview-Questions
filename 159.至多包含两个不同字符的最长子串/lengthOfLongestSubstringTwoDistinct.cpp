class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int left=0,right=0;
        unordered_map<char, int> mp;
        int cnt = 0;
        int ans = 0;

        while(right<s.size())
        {
            mp[s[right]] ++;
            if (mp[s[right]] == 1)
            {
                cnt ++;
            }
            while (cnt > 2) 
            {
                mp[s[left]] --;

                if(mp[s[left]]==0)
                {
                    cnt--;
                }
                left++;
            }

            ans = max(ans, right - left + 1);
            right++;
        }

        return ans;
    }
};