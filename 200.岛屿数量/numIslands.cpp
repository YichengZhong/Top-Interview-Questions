class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        int m=grid.size();
        if(m==0)
        {
            return 0;
        }
        
        int n=grid[0].size();
        int count=0;

        if(m==0 || n==0)
        {
            return count;
        }

        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(grid[i][j]=='1')
                {
                    count++;
                    dfs(i,j,grid);
                }
            }
        }

        return count;
        
    }

    void dfs(int r,int c,vector<vector<char>>& grid)
    {
        int nr = grid.size();
        int nc = grid[0].size();

        grid[r][c] = '0';
        if (r - 1 >= 0 && grid[r-1][c] == '1') 
        {
            dfs(r - 1,c,grid);
        }

        if (r + 1 < nr && grid[r+1][c] == '1') 
        {
            dfs(r + 1,c,grid);
        }

        if (c - 1 >= 0 && grid[r][c-1] == '1') 
        {
            dfs(r, c - 1,grid);
        }

        if (c + 1 < nc && grid[r][c+1] == '1') 
        {
            dfs(r, c + 1,grid);
        }
    }
};