class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        unordered_map<int,int> memo;
        const int MOD = 1e9 + 7;
        long long ans = 0;
        for (int i = 0;i < deliciousness.size();++i)
        {
            //隐含上限控制
            for (int j = 0;j < 22;++j)
            {
                int target = pow(2,j);
                if (target - deliciousness[i] < 0) continue;
                if (memo.count(target - deliciousness[i]))
                {
                    ans += memo[target - deliciousness[i]];
                }
            }
            ++memo[deliciousness[i]];
        }
        ans %= MOD;
        return ans;
    }


};