class Solution 
{
    public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) 
    {
        vector<int> res;
        res.clear();
        
        for (auto q: queries)
        {
            int x0 = q[0], y0 = q[1], R = q[2];
            int cnt = 0;

            for (auto p: points)
            {
                int x = p[0],y = p[1];

                if (pow(x-x0, 2) + pow(y-y0, 2) <= pow(R, 2))
                    cnt ++;
            }
            res.push_back(cnt);
        }

        return res;
    }
};