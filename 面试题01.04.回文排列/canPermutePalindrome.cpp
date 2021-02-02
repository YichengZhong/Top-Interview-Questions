class Solution {
public:
    bool canPermutePalindrome(string s) {
        map<char,int>map_s;

        for(int i=0;i<s.size();++i)
        {
            map_s[s[i]]++;
        }

        int flag=0; //最多只能有一个是奇数
        for(auto iter=map_s.begin();iter!=map_s.end();++iter)
        {
            if(iter->second%2==0) continue;
            if(iter->second%2==1)
            {
                if(flag==0)
                {
                    flag=1;
                    continue;
                }
                else
                {
                    return false;
                }
            }
        }

        return true;
    }
};