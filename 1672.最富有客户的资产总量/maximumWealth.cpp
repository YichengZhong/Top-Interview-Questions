class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max_n = 0;
        for(auto i : accounts) 
        {
            int sum = 0;
            for(auto j : i) 
            {
                sum += j;
            }
            max_n = max(max_n, sum);
        }
        return max_n;
    }
};