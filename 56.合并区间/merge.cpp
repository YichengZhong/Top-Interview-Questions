class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(), intervals.end(), cmp);
        if(intervals.size() == 1)
            return intervals;
        vector<vector<int>> res;
        int i = 0;
        while(i < intervals.size())
        {
            int start = intervals[i][0], end = intervals[i][1];
            int j = i+1;
            while(j < intervals.size() && intervals[j][0] <= end)
            {
                if(end < intervals[j][1])
                    end = intervals[j][1];
                j++;
            }
            vector<int>temp;
            temp.push_back(start);
            temp.push_back(end);
            res.push_back(temp);
            i = j;
        }
        return res;

    }

    static bool cmp(vector<int> a, vector<int> b)
    {
        return a[0] < b[1];
    }
};