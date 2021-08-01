class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) 
    {
        priority_queue<pair<int, int>> q;
        int n = mat.size();
        for(int i = 0; i < n; i++) 
        {
            // 记录当前行士兵个数
            int cnt = 0;
            for(int x : mat[i]) 
            {
                // x = 0 不会影响结果
                cnt += x;
            }
            q.push({cnt, i});
        }

        // 当前优先队列是从强到弱排的
        vector<int> ret;
        while(q.size() > k) q.pop();
        while(!q.empty()) 
        {
            ret.push_back(q.top().second);
            q.pop();
        } 
        
        reverse(ret.begin(), ret.end());
        
        return ret;
    }
};