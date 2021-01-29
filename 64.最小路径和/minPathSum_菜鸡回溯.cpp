class Solution {
public:
    int minValue;
    int minPathSum(vector<vector<int>>& grid) {
        minValue=INT_MAX;

        helpDFS(grid,0,0,grid[grid.size()-1][grid[0].size()-1]);

        return minValue;
    }

    void helpDFS(vector<vector<int>>& grid,int index_i,int index_j,int sum)
    {
        if(index_i>=grid.size()-1 && index_j>=grid[0].size()-1)
        {
            minValue=min(minValue,sum);
            return;
        }

        if(index_i<grid.size()-1 && index_j<=grid[0].size()-1)
        {
            helpDFS(grid,index_i+1,index_j,sum+grid[index_i][index_j]);
        }

        if(index_i<=grid.size()-1 && index_j<grid[0].size()-1)
        {
            helpDFS(grid,index_i,index_j+1,sum+grid[index_i][index_j]);
        }    
    }
};