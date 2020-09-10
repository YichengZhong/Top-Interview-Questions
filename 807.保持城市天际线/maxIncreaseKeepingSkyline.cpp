class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int>max_col;
        vector<int>max_raw;

        max_col.clear();
        max_raw.clear();

        for(int i=0;i<grid.size();++i)
        {
            auto it=max_element(grid[i].begin(), grid[i].end());
            max_raw.push_back(*it);
        }

        for(int j=0;j<grid[0].size();++j)
        {
            vector<int>tmp;
            tmp.clear();

            for(int i=0;i<grid.size();++i)
            {
                tmp.push_back(grid[i][j]);
            }

            auto it=max_element(tmp.begin(), tmp.end());
            max_col.push_back(*it);
        }

        int sum=0;

        for(int i=0;i<grid.size();++i)
        {
            for(int j=0;j<grid[0].size();++j)
            {
                int temp=min(max_raw[i],max_col[j])-grid[i][j];

                sum=sum+temp;
            }
        }

        return sum;
    }
};